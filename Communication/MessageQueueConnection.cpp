//
// Created by pawel on 12.06.2020.
//

#include "MessageQueueConnection.h"
#include <iostream>
void MessageQueueConnection::open(std::string &name, mode_t mode) {
    input_mq = mq_open(name.c_str(), mode);
    if(input_mq < 0){
        perror("open");
        throw std::runtime_error("open mq failed");
    }
}

void MessageQueueConnection::close() {
    mq_close(input_mq);
    mq_close(output_mq);
}

void MessageQueueConnection::create(std::string &name) {
    struct mq_attr attr;
    attr.mq_msgsize = 8192L;
    attr.mq_maxmsg = 10L;
    mode_t mode = S_IRWXO;
    output_mq = mq_open(name.c_str(), O_WRONLY | O_CREAT, PERMS, &attr);
    if(output_mq < 0){
        perror("create");
        throw std::runtime_error("queue not created");
    }
}

void MessageQueueConnection::remove(std::string &name) {
    mq_unlink((const char *)(&name));
}

void MessageQueueConnection::send(Message &msg) {
    if(output_mq < 0)
        throw std::runtime_error("mq not open");
    if(mq_send(output_mq, (const char *)&(msg), sizeof(msg), 1) < 0){
        perror("sending");
        throw std::runtime_error("sending problem");
    }
}

cv::Mat MessageQueueConnection::read() {
    if(input_mq < 0)
        throw std::runtime_error("mq not open");
    Message msg;
    unsigned int prio = 1;
    if(mq_receive(input_mq, (char *)&(msg), 8192, &prio) < 0){
        perror("receive");
        throw std::runtime_error("receive problem");
    }
    return msg.produceFrame();
}