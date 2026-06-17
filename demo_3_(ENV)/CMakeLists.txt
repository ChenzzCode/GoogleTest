cmake_minimum_required(VERSION 3.10)

project(test)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_executable(gtest ${CMAKE_SOURCE_DIR}/source/main.cpp)

target_include_directories(gtest PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(gtest GTest::gtest GTest::gtest_main)
