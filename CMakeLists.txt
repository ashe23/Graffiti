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
if(MSVC)
	# set to c++17 standard in visual studio project
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
	# Hide the console window in visual studio project
	# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(MSVC)

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