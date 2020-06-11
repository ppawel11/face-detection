//
// Created by pawel on 01.06.2020.
//

#ifndef DETECTOR_CONNECTION_H
#define DETECTOR_CONNECTION_H

#include <opencv2/core/core.hpp>

#include <mqueue.h>
#include "Message.h"

class Connection {
    int mq;

public:
    Connection() {};
    cv::Mat read();

    void openMQ();
    void closeMQ();
};


#endif //DETECTOR_CONNECTION_H
