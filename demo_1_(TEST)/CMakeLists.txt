cmake_minimum_required(VERSION 3.10)

project(ProjectTest)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_executable(maintest ${CMAKE_SOURCE_DIR}/source/main.cpp)
target_include_directories(maintest PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(maintest GTest::gtest GTest::gtest_main)
