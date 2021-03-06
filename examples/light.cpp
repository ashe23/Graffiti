#define STB_IMAGE_IMPLEMENTATION#include "Core.hpp"void processInput(GLFWwindow *window);void framebuffer_size_callback(GLFWwindow *window, int width, int height);void mouse_callback(GLFWwindow *window, double xpos, double ypos);void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);bool firstMouse = true;float yaw = -90.0f;    // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.float pitch = 0.0f;float lastX = SCR_WIDTH / 2.0;float lastY = SCR_HEIGHT / 2.0;float fov = 45.0f;float trans = 1.0f;// lightingglm::vec3 lightPos(1.2f, 1.0f, 2.0f);int main() {    // init opengl core    Graffiti::Core core;    core.init();    // create window    Graffiti::Window window(SCR_WIDTH, SCR_HEIGHT, "Light", false);    window.setPolygonMode(false);    core.enable3D();    //glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);    glfwSetFramebufferSizeCallback(window.getWindow(), framebuffer_size_callback);    glfwSetCursorPosCallback(window.getWindow(), mouse_callback);    glfwSetScrollCallback(window.getWindow(), scroll_callback);    // loading shaders    Graffiti::Shader ourShader;    Graffiti::Shader lightingShader;    Graffiti::Shader lampShader;    ourShader.attach("shaders/model.vert", Graffiti::ShaderType::VERTEX);    ourShader.attach("shaders/model.frag", Graffiti::ShaderType::FRAGMENT);    lightingShader.attach("shaders/light/light.vert", Graffiti::ShaderType::VERTEX);    lightingShader.attach("shaders/light/light.frag", Graffiti::ShaderType::FRAGMENT);    lampShader.attach("shaders/light/lamp.vert", Graffiti::ShaderType::VERTEX);    lampShader.attach("shaders/light/lamp.frag", Graffiti::ShaderType::FRAGMENT);    // set up vertex data (and buffer(s)) and configure vertex attributes    // ------------------------------------------------------------------    float vertices[] = {            -0.5f, -0.5f, -0.5f,            0.5f, -0.5f, -0.5f,            0.5f,  0.5f, -0.5f,            0.5f,  0.5f, -0.5f,            -0.5f,  0.5f, -0.5f,            -0.5f, -0.5f, -0.5f,            -0.5f, -0.5f,  0.5f,            0.5f, -0.5f,  0.5f,            0.5f,  0.5f,  0.5f,            0.5f,  0.5f,  0.5f,            -0.5f,  0.5f,  0.5f,            -0.5f, -0.5f,  0.5f,            -0.5f,  0.5f,  0.5f,            -0.5f,  0.5f, -0.5f,            -0.5f, -0.5f, -0.5f,            -0.5f, -0.5f, -0.5f,            -0.5f, -0.5f,  0.5f,            -0.5f,  0.5f,  0.5f,            0.5f,  0.5f,  0.5f,            0.5f,  0.5f, -0.5f,            0.5f, -0.5f, -0.5f,            0.5f, -0.5f, -0.5f,            0.5f, -0.5f,  0.5f,            0.5f,  0.5f,  0.5f,            -0.5f, -0.5f, -0.5f,            0.5f, -0.5f, -0.5f,            0.5f, -0.5f,  0.5f,            0.5f, -0.5f,  0.5f,            -0.5f, -0.5f,  0.5f,            -0.5f, -0.5f, -0.5f,            -0.5f,  0.5f, -0.5f,            0.5f,  0.5f, -0.5f,            0.5f,  0.5f,  0.5f,            0.5f,  0.5f,  0.5f,            -0.5f,  0.5f,  0.5f,            -0.5f,  0.5f, -0.5f,    };    // first, configure the cube's VAO (and VBO)    unsigned int VBO, cubeVAO;    glGenVertexArrays(1, &cubeVAO);    glGenBuffers(1, &VBO);    glBindBuffer(GL_ARRAY_BUFFER, VBO);    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);    glBindVertexArray(cubeVAO);    // position attribute    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);    glEnableVertexAttribArray(0);    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)    unsigned int lightVAO;    glGenVertexArrays(1, &lightVAO);    glBindVertexArray(lightVAO);    // we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)    glBindBuffer(GL_ARRAY_BUFFER, VBO);    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);    glEnableVertexAttribArray(0);    // loading model    std::string modelPath = Graffiti::Util::getPath("assets/meshes/cube.obj");    Graffiti::Model ourModel(modelPath, false);    glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);    // game loop    while (!glfwWindowShouldClose(window.getWindow())) {        // update global timers        core.update();        processInput(window.getWindow());        // background        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);        // rendering lamp        // be sure to activate shader when setting uniforms/drawing objects//        lightingShader.use();//        lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);//        lightingShader.setVec3("lightColor",  1.0f, 1.0f, 1.0f);////        // view/projection transformations//        lightingShader.setMat4("projection", projection);//        lightingShader.setMat4("view", view);        // world transformation        glm::mat4 model;//        lightingShader.setMat4("model", model);        // render the cube//        glBindVertexArray(cubeVAO);//        glDrawArrays(GL_TRIANGLES, 0, 36);        // Our model        ourShader.use();        ourShader.setMat4("projection", projection);        ourShader.setMat4("view", view);        // render the loaded model        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down        ourShader.setMat4("model", model);        ourModel.Draw(ourShader);        // rendering lamp        lampShader.use();        lampShader.setMat4("projection", projection);        lampShader.setMat4("view", view);        model = glm::mat4();        model = glm::translate(model, lightPos);        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube        lampShader.setMat4("model", model);        glBindVertexArray(lightVAO);        glDrawArrays(GL_TRIANGLES, 0, 36);        // glfw input handlers        glfwSwapBuffers(window.getWindow());        glfwPollEvents();    }    glfwTerminate();    return 0;}void processInput(GLFWwindow *window) {    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)        glfwSetWindowShouldClose(window, true);    float cameraSpeed = 0.05f; // adjust accordingly    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)        cameraPos += cameraSpeed * cameraFront;    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)        cameraPos -= cameraSpeed * cameraFront;    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;}// glfw: whenever the window size changed (by OS or user resize) this callback function executes// ---------------------------------------------------------------------------------------------void framebuffer_size_callback(GLFWwindow *window, int width, int height) {    // make sure the viewport matches the new window dimensions; note that width and    // height will be significantly larger than specified on retina displays.    glViewport(0, 0, width, height);}// glfw: whenever the mouse moves, this callback is called// -------------------------------------------------------void mouse_callback(GLFWwindow *window, double xpos, double ypos) {    if (firstMouse) {        lastX = xpos;        lastY = ypos;        firstMouse = false;    }    float xoffset = xpos - lastX;    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top    lastX = xpos;    lastY = ypos;    float sensitivity = 0.1f; // change this value to your liking    xoffset *= sensitivity;    yoffset *= sensitivity;    yaw += xoffset;    pitch += yoffset;    // make sure that when pitch is out of bounds, screen doesn't get flipped    if (pitch > 89.0f)        pitch = 89.0f;    if (pitch < -89.0f)        pitch = -89.0f;    glm::vec3 front;    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));    front.y = sin(glm::radians(pitch));    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));    cameraFront = glm::normalize(front);}// glfw: whenever the mouse scroll wheel scrolls, this callback is called// ----------------------------------------------------------------------void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {    trans -= yoffset / 10;    if (trans < 0.0f) {        trans = 0.0f;    }    if (trans > 1.0f) {        trans = 1.0f;    }    if (fov >= 1.0f && fov <= 45.0f)        fov -= yoffset;    if (fov <= 1.0f)        fov = 1.0f;    if (fov >= 45.0f)        fov = 45.0f;}