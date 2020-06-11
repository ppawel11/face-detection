//
// Created by pawel on 01.06.2020.
//

#include <iostream>
#include "Connection.h"


cv::Mat Connection::read(){
    char buf[9000];
    Message msg;
    unsigned int prio = 1;
    if(mq_receive(mq, (char *)&(msg), 8192,&prio) < 0){
        perror("receive");
        throw std::runtime_error("receive problem");
    }

    std::cout<<msg.mtype<<std::endl;
    return msg.produceFrame();
}

void Connection::openMQ(){
    char * name = "/first_q";
    mq = mq_open(name, O_RDONLY);
    if(mq < 0){
        perror("open");
        throw std::runtime_error("open mq failed");
    }
}

void Connection::closeMQ(){
    mq_close(mq);
}