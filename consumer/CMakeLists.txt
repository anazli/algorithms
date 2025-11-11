cmake_minimum_required(VERSION 3.15)

project(hello_world_consumer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(hello_world_consumer main.cpp)

target_link_libraries(hello_world_consumer
    PRIVATE
        algorithms::algorithms
)

target_compile_features(hello_world_consumer PRIVATE cxx_std_20)
