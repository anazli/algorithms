cmake_minimum_required(VERSION 3.15)

project(consumer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the algorithms library via Conan (CMakeDeps)
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/build/Release/generators")
find_package(algorithms REQUIRED)

add_executable(consumer main.cpp)

target_link_libraries(consumer
    PRIVATE
        algorithms::algorithms
)

target_compile_features(consumer PRIVATE cxx_std_20)
