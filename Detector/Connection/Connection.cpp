//
// Created by pawel on 01.06.2020.
//

#include <iostream>
#include "Connection.h"


cv::Mat Connection::read(){
    Message msg;
    unsigned int prio = 1;
    if(mq_receive(mq_recv, (char *)&(msg), 8192, &prio) < 0){
        perror("receive");
        throw std::runtime_error("receive problem");
    }
    return msg.produceFrame();
}

void Connection::openReceivingMQ(){
    mq_recv = mq_open((char*)"/producer-detector-mq", O_RDONLY);
    if(mq_recv < 0){
        perror("open");
        throw std::runtime_error("open mq_recv failed");
    }
}

void Connection::closeReceivingMQ(){
    mq_close(mq_recv);
}

void Connection::createSendingMQ() {
    char * queue_name = {(char*)"/detector-archiver-mq"};
    struct mq_attr attr;
    attr.mq_msgsize = 8192L;
////    attr.mq_flags = 0L;
////    attr.mq_curmsgs = 0L;
    attr.mq_maxmsg = 10L;
    mq_sending = mq_open(queue_name, O_WRONLY | O_CREAT, PERMS, &attr);
    if(mq_sending < 0){
        perror("create");
        throw std::runtime_error("detector-archiver queue not created");
    }
}

void Connection::deleteSendingMQ() {
    const char * name = {"/detector-archiver-mq"};
    mq_unlink("/detector-archiver-mq");
}

void Connection::sendData(Message & msg) {
    if(mq_send(mq_sending, (const char *)&(msg), sizeof(msg), 1) < 0){
        perror("sending");
        throw std::runtime_error("sending problem");
    }
}