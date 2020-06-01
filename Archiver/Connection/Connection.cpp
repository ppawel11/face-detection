//
// Created by pawel on 01.06.2020.
//

#include "Connection.h"



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
