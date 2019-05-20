cmake_minimum_required(VERSION 2.8)

project(ch16)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

find_package(OpenCV 3.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(example_16_1 example_16_1.cpp)
target_link_libraries(example_16_1 ${OpenCV_LIBS})
