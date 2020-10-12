cmake_minimum_required(VERSION 3.10)
project(Graffiti)


# glfw
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(vendor/glfw)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(
	include/
	vendor/glfw/include/
	vendor/glad/include/
)

# pathes
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")
file(GLOB VENDOR_GLAD_SOURCES "vendor/glad/src/glad.c")

add_executable(Graffiti ${SOURCES} ${HEADERS} ${VENDOR_GLAD_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})