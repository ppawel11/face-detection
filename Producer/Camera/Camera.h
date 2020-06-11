//
// Created by pawel on 11.06.2020.
//

#ifndef PRODUCER_CAMERA_H
#define PRODUCER_CAMERA_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Camera {
    cv::VideoCapture cam;
public:
    Camera() {};
    ~Camera();
    cv::Mat read();
    void close();
    void init();
};


#endif //PRODUCER_CAMERA_H
