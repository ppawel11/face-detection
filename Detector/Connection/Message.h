//
// Created by pawel on 11.06.2020.
//

#ifndef DETECTOR_MESSAGE_H
#define DETECTOR_MESSAGE_H

#include <ctime>
#include <vector>
#include <opencv2/core/core.hpp>

struct Message{
    long mtype;
    int timestamp;
    int height;
    int width;
    char pixels[90*90] = {0};

    cv::Mat produceFrame(){
        cv::Mat frame(height, width, CV_8UC1);
        for(int i = 0; i<frame.rows; ++i)
            for(int j = 0; j<frame.cols; ++j){
                frame.at<uchar>(i,j) = pixels[i*90+j];
            }
        return frame;
    }
};

#endif //DETECTOR_MESSAGE_H
