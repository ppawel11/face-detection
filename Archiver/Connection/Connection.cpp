//
// Created by pawel on 01.06.2020.
//

#include "Connection.h"


void Connection::openReceivingMQ(){
    mq_receiving = mq_open((char*)"/detector-archiver-mq", O_RDONLY);
    if(mq_receiving < 0){
        perror("open");
        throw std::runtime_error("open mq_receiving failed");
    }
}

void Connection::closeReceivingMQ(){
    mq_close(mq_receiving);
}

cv::Mat Connection::receiveData() {
    Message msg;
    unsigned int prio = 1;
    if(mq_receive(mq_receiving, (char *)&(msg), 8192, &prio) < 0){
        perror("receive");
        throw std::runtime_error("receive problem");
    }
    return msg.produceFrame();
}
