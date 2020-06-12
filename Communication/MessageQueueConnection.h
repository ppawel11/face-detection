//
// Created by pawel on 12.06.2020.
//

#ifndef FACEDETECTION_MESSAGEQUEUECONNECTION_H
#define FACEDETECTION_MESSAGEQUEUECONNECTION_H

#include "Connection.h"
#include "Message.h"
#include <mqueue.h>

#define PERMS 0666

class MessageQueueConnection: public Connection {
    int input_mq = -1;
    int output_mq = -1;
public:
    MessageQueueConnection() = default;

    void open(std::string &name, mode_t mode) override;
    void close() override ;
    void create(std::string &name) override ;
    void remove(std::string &name) override ;

    void send(Message &msg) override ;
    cv::Mat read() override;
};


#endif //FACEDETECTION_MESSAGEQUEUECONNECTION_H
