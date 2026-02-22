cmake_minimum_required(VERSION 3.15)

project(algorithms_tests LANGUAGES CXX)

if(DEFINED CONAN_GTEST_ROOT)
  set(GTest_DIR "${CONAN_GTEST_ROOT}/lib/cmake/GTest")
endif()

# Find GTest (either from Conan env or system)
find_package(GTest REQUIRED)

add_executable(algorithms_test
  list_test.cpp
  stack_test.cpp
  vector_test.cpp
)

target_include_directories(algorithms_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(algorithms_test PRIVATE GTest::gtest GTest::gtest_main gmock algorithms)

include(GoogleTest)
gtest_discover_tests(algorithms_test)
