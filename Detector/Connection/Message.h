//
// Created by pawel on 11.06.2020.
//

#ifndef DETECTOR_MESSAGE_H
#define DETECTOR_MESSAGE_H

#include <ctime>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>

struct Message{
    long mtype;
    int timestamp;
    int height;
    int width;
    char pixels[90*90] = {0};

    Message() {}

    cv::Mat produceFrame(){
        cv::Mat frame(height, width, CV_8UC1);
        for(int i = 0; i<frame.rows; ++i)
            for(int j = 0; j<frame.cols; ++j){
                frame.at<uchar>(i,j) = pixels[i*90+j];
            }
        return frame;
    }

    Message(const cv::Mat& frame) {
        mtype = 0;
        timestamp = time(nullptr);
        height = frame.rows;
        width = frame.cols;
        for (int i = 0; i < frame.rows; ++i)
            for (int j = 0; j < frame.cols; ++j)
                pixels[i*90+j] = frame.at<uchar>(i, j);
    }
};

#endif //DETECTOR_MESSAGE_H
