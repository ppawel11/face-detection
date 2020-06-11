//
// Created by pawel on 11.06.2020.
//

#include "Camera.h"

cv::Mat Camera::read() {
    cv::Mat frame;
    cv::Mat frame_gray;
    cam.read(frame);
    cvtColor( frame, frame_gray, cv::COLOR_BGR2GRAY );
    return frame_gray;
}

void Camera::init() {
    cam.open(0);
    if(!cam.isOpened())
        throw std::runtime_error("camera not opened");
}

void Camera::close() {
    cam.release();
}

Camera::~Camera() {
    if(cam.isOpened())
        close();
}
