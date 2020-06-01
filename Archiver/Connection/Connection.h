//
// Created by pawel on 01.06.2020.
//

#ifndef DETECTOR_CONNECTION_H
#define DETECTOR_CONNECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Connection {
    cv::VideoCapture cam;

public:
    Connection() {};


    cv::Mat getCameraInput();
    int initCam();
    void closeCam();
};


#endif //DETECTOR_CONNECTION_H
