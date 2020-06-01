cmake_minimum_required(VERSION 3.16)
project(Detector)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )

add_executable(Detector main.cpp Connection/Connection.cpp Connection/Connection.h Detection/Detector.cpp Detection/Detector.h)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
