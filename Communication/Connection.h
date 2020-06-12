//
// Created by pawel on 12.06.2020.
//

#ifndef FACEDETECTION_CONNECTION_H
#define FACEDETECTION_CONNECTION_H

#include <string>
#include <opencv2/core/core.hpp>
#include "Message.h"

class Connection {
public:
    virtual void open(std::string &name, mode_t mode) = 0;
    virtual void close() = 0;
    virtual void create(std::string &name) = 0;
    virtual void remove(std::string &name) = 0;

    virtual void send(Message &msg) = 0;
    virtual cv::Mat read() = 0;
};


#endif //FACEDETECTION_CONNECTION_H
