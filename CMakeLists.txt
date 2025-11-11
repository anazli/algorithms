cmake_minimum_required(VERSION 3.15)

project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/build/Release/generators")

add_library(algorithms
	src/hello_world.cpp
)

target_include_directories(algorithms
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_compile_features(algorithms PUBLIC cxx_std_20)

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
	enable_testing()
	add_subdirectory(test)
endif()

