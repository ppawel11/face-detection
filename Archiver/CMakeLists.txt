cmake_minimum_required(VERSION 3.16)
project(Archiver)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )

add_executable(Archiver main.cpp Connection/Connection.cpp Connection/Connection.h Connection/Message.h)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} -lrt )