//
// Created by pawel on 12.06.2020.
//

#ifndef FACEDETECTION_MESSGAE_H
#define FACEDETECTION_MESSGAE_H

#include <opencv2/core/core.hpp>
#include <ctime>

struct Message{
    long mtype;
    int timestamp;
    int height;
    int width;;
    uchar pixels[90*90];

    Message() {}

    Message(const cv::Mat& frame){
        mtype = 0;
        timestamp = time(nullptr);
        height = frame.rows;
        width = frame.cols;
        for (int i = 0; i < frame.rows; ++i)
            for (int j = 0; j < frame.cols; ++j)
                pixels[i*90+j] = frame.at<uchar>(i, j);
    }

    cv::Mat produceFrame(){
        cv::Mat frame(height, width, CV_8UC1);

        for(int i = 0; i<frame.rows; ++i)
            for(int j = 0; j<frame.cols; ++j)
                frame.at<uchar>(i,j) = pixels[i*90+j];
        return frame;
    }

};

#endif //FACEDETECTION_MESSGAE_H
