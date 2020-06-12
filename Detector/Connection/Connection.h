//
// Created by pawel on 01.06.2020.
//

#ifndef DETECTOR_CONNECTION_H
#define DETECTOR_CONNECTION_H

#include <opencv2/core/core.hpp>

#include <mqueue.h>
#include "Message.h"

#define PERMS 0666

class Connection {
    int mq_recv;
    int mq_sending;

public:
    Connection() {};
    cv::Mat read();

    void openReceivingMQ();
    void closeReceivingMQ();

    void createSendingMQ();
    void deleteSendingMQ();
    void sendData(Message & msg);
};


#endif //DETECTOR_CONNECTION_H
