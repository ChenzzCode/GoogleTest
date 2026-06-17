cmake_minimum_required(VERSION 3.10)

project(main)

# 要求C++标准
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_executable(testf ${CMAKE_SOURCE_DIR}/source/main.cpp)
target_include_directories(testf PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(testf GTest::gtest GTest::gtest_main)

