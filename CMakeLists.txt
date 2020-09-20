cmake_minimum_required(VERSION 2.8)

project(LSDDetector)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(OpenCV_DIR "/opencv/cmake/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}./Detection)
set(LINE_DETECTION Detection/lsd.cpp       Detection/lsd.h)


add_executable(LSD ${LINE_DETECTION}
                            detection.hpp   detection.cpp
                            main.cpp)
target_link_libraries(LSD ${OpenCV_LIBS})


