cmake_minimum_required(VERSION 3.10)
project(Graffiti)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)



# pathes
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(Graffiti ${SOURCES} ${HEADERS})