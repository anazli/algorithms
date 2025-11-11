cmake_minimum_required(VERSION 3.15)

project(algorithms_tests LANGUAGES CXX)

if(DEFINED CONAN_GTEST_ROOT)
  set(GTest_DIR "${CONAN_GTEST_ROOT}/lib/cmake/GTest")
endif()

# Find GTest (either from Conan env or system)
find_package(GTest REQUIRED)

add_executable(test_algorithms
  test_hello_world.cpp
)

target_include_directories(test_algorithms PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_algorithms PRIVATE GTest::gtest GTest::gtest_main algorithms)

include(GoogleTest)
gtest_discover_tests(test_algorithms)
