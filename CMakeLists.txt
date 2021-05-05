cmake_minimum_required(VERSION 3.18...3.20)

project(Graffiti
	VERSION 1.0
	DESCRIPTION "Simple OpenGL project"
	LANGUAGES CXX C
)


# git submodules
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
	find_package(Git QUIET)
	if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
		# Update submodules as needed
		option(GIT_SUBMODULE "Check submodules during build" ON)
		if(GIT_SUBMODULE)
			message(STATUS "Submodule update")
			execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
							WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
							RESULT_VARIABLE GIT_SUBMOD_RESULT)
			if(NOT GIT_SUBMOD_RESULT EQUAL "0")
				message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
			endif()
		endif()
	endif()
endif()

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
# add_subdirectory(external/glfw)

# glad
# include_directories(external/glad/include)
# set(GLAD_SRC external/glad/src/glad.c)

# spdlog
# add_subdirectory(external/spdlog)

# glm
# add_subdirectory(external/glm)

add_subdirectory(apps)

# add_executable(${PROJECT_NAME} main.cpp ${GLAD_SRC})
# target_link_libraries(${PROJECT_NAME} glfw spdlog glm)
