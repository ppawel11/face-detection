//
// Created by pawel on 11.06.2020.
//

#ifndef PRODUCER_MESSAGE_H
#define PRODUCER_MESSAGE_H

#include <opencv2/core/core.hpp>

#include <ctime>
#include <vector>

struct Message{
    long mtype;
    int timestamp;
    int height;
    int width;;
    uchar pixels[90*90];

    Message(const cv::Mat& frame) {
        cv::Mat resized = cv::Mat();
        cv::resize(frame, resized, cv::Size(90, 90), 0, 0, CV_INTER_CUBIC);

        mtype = 0;
        timestamp = time(nullptr);
        height = resized.rows;
        width = resized.cols;
        for (int i = 0; i < resized.rows; ++i)
            for (int j = 0; j < resized.cols; ++j)
                pixels[i*90+j] = resized.at<uchar>(i, j);

    }

};

#endif //PRODUCER_MESSAGE_H
