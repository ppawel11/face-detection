cmake_minimum_required(VERSION 3.16)
project(Producer)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )

add_executable(Producer main.cpp Connection/Connection.cpp Connection/Connection.h Connection/Message.h Camera/Camera.cpp Camera/Camera.h)

#include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} -lrt )


