add_executable(Main main.cpp)
target_link_libraries(Main glfw glad)
target_compile_features(Main PRIVATE cxx_std_17)
