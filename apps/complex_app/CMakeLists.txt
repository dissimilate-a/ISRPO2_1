add_executable(complex_app main.cpp)

# Link against the complex library target from sample_lib
target_link_libraries(complex_app PRIVATE complex)

target_compile_features(complex_app PRIVATE cxx_std_17)
