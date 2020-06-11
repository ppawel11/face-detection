//
// Created by pawel on 01.06.2020.
//

#ifndef DETECTOR_DETECTOR_H
#define DETECTOR_DETECTOR_H

#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

class Detector {
    cv::CascadeClassifier face_classifier;

    std::vector<cv::Rect> detect(cv::Mat frame);
    void markDetectedFaces(cv::Mat frame, const std::vector<cv::Rect>& faces);

public:
    Detector();
    void detectAndMarkFaces(cv::Mat frame);
};


#endif //DETECTOR_DETECTOR_H
