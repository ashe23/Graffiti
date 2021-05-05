cmake_minimum_required(VERSION 3.18...3.20)

project(Graffiti
	VERSION 1.0
	DESCRIPTION "Simple OpenGL project"
	LANGUAGES CXX C
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	message(STATUS "64 bits")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	message(STATUS "32 bits")
endif()


# compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# glfw
# set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
# set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
# set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
# set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
# add_subdirectory(external/glfw)

# glad
# include_directories(external/glad/include)
# set(GLAD_SRC external/glad/src/glad.c)

# spdlog
# add_subdirectory(external/spdlog)

# glm
# add_subdirectory(external/glm)

add_subdirectory(external)
add_subdirectory(apps)

# add_executable(${PROJECT_NAME} main.cpp ${GLAD_SRC})
# target_link_libraries(${PROJECT_NAME} glfw spdlog glm)
