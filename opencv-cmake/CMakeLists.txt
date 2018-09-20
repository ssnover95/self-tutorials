cmake_minimum_required(VERSION 3.10)
project(test_opencv)

set(OpenCV_DIR $ENV{OPENCV_PATH})
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)

include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_executable(test_opencv main.cpp)
target_link_libraries(test_opencv ${OpenCV_LIBS})