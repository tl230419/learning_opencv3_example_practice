cmake_minimum_required(VERSION 2.8)

project(ch2)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(example_2_1 example_2_1.cpp)
target_link_libraries(example_2_1 ${OpenCV_LIBS})

add_executable(example_2_3 example_2_3.cpp)
target_link_libraries(example_2_3 ${OpenCV_LIBS})

add_executable(example_2_4 example_2_4.cpp)
target_link_libraries(example_2_4 ${OpenCV_LIBS})

add_executable(example_2_5 example_2_5.cpp)
target_link_libraries(example_2_5 ${OpenCV_LIBS})

add_executable(example_2_6 example_2_6.cpp)
target_link_libraries(example_2_6 ${OpenCV_LIBS})

add_executable(example_2_7 example_2_7.cpp)
target_link_libraries(example_2_7 ${OpenCV_LIBS})

add_executable(example_2_10 example_2_10.cpp)
target_link_libraries(example_2_10 ${OpenCV_LIBS})

add_executable(example_2_11 example_2_11.cpp)
target_link_libraries(example_2_11 ${OpenCV_LIBS})
