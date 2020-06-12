//
// Created by pawel on 12.06.2020.
//

#ifndef ARCHIVER_MESSAGE_H
#define ARCHIVER_MESSAGE_H

#include <opencv2/core/core.hpp>

#include <ctime>
#include <vector>

#include "iostream"

struct Message{
    long mtype;
    int timestamp;
    int height;
    int width;;
    uchar pixels[90*90];

    Message() {}

    cv::Mat produceFrame(){
        std::cout<<height<<" "<<width<<" "<<pixels[10]<<std::endl;
        cv::Mat frame(height, width, CV_8UC1);

        for(int i = 0; i<frame.rows; ++i)
            for(int j = 0; j<frame.cols; ++j)
                frame.at<uchar>(i,j) = pixels[i*90+j];
        return frame;
    }

};

#endif //ARCHIVER_MESSAGE_H
