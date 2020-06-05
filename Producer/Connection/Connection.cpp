//
// Created by pawel on 01.06.2020.
//

#include "Connection.h"

cv::Mat Connection::readFromFile(std::string &&path) {
    cv::Mat image = imread(path, cv::IMREAD_COLOR);
    if(image.empty())
        throw std::runtime_error("image not found");
    cv::imshow("reader", image);
    return image;
}

cv::Mat Connection::getCameraInput() {
    cv::Mat frame;
    cam.read(frame);
    return frame;
}

int Connection::initCam() {
    cam.open(0);
    if(!cam.isOpened())
        return -1;
    return 0;
}

void Connection::closeCam() {
    cam.release();
}