cmake_minimum_required(VERSION 3.0)
project(Graffiti)

# glfw
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(vendor/glfw)

# assimp
#option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
#option(ASSIMP_BUILD_SAMPLES OFF)
#option(ASSIMP_BUILD_TESTS OFF)
#add_subdirectory(vendor/assimp)

# compiler flags
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

include_directories(  
  examples/
  include/
  vendor/glad/include/
  vendor/glfw/include/
  vendor/glm/
  vendor/stb/
  vendor/catch/include/
  vendor/filesystem/
)

file(GLOB VENDORS_SOURCES vendor/glad/src/glad.c)
file(GLOB PROJECT_HEADERS include/*.hpp)
file(GLOB PROJECT_SOURCES src/*.cpp)
file(GLOB PROJECT_EXAMPLES examples/main_3d.cpp)
file(GLOB PROJECT_SHADERS shaders/*.frag shaders/*.vert)
file(GLOB FILESYSTEM_VENDOR vendor/filesystem/filesystem/*.h)


file(GLOB PROJECT_CONFIGS 
  CMakeLists.txt
  Readme.md
  .gitattributes
  .gitignore
  .gitmodules
)

source_group("headers" FILES ${PROJECT_HEADERS})
source_group("shaders" FILES ${PROJECT_SHADERS})
source_group("sources" FILES ${PROJECT_SOURCES})
source_group("examples" FILES ${PROJECT_EXAMPLES})
source_group("vendors" FILES ${VENDORS_SOURCES} ${FILESYSTEM_VENDOR})

add_definitions(-DGLFW_INCLUDE_NONE -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_SHADERS} ${PROJECT_CONFIGS} ${VENDORS_SOURCES} ${PROJECT_EXAMPLES} ${FILESYSTEM_VENDOR})
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})