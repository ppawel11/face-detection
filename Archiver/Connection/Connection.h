//
// Created by pawel on 01.06.2020.
//

#ifndef DETECTOR_CONNECTION_H
#define DETECTOR_CONNECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <mqueue.h>
#include "Message.h"

class Connection {
    int mq_receiving;

public:
    Connection() {};

    void openReceivingMQ();
    void closeReceivingMQ();

    cv::Mat receiveData();
};


#endif //DETECTOR_CONNECTION_H
