cmake_minimum_required(VERSION 3.16)
project(FaceDetection)

set(CMAKE_CXX_STANDARD 14)
find_package( OpenCV REQUIRED )

add_subdirectory(Detector)
add_subdirectory(Producer)
add_subdirectory(Archiver)
