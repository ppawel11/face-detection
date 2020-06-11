//
// Created by pawel on 01.06.2020.
//

#include <iostream>
#include <fcntl.h>
#include "Connection.h"

void Connection::createMQ() {
    char * queue_name = {"/first_q"};
    struct mq_attr attr;
    attr.mq_msgsize = 8192L;
//    attr.mq_flags = 0L;
//    attr.mq_curmsgs = 0L;
    attr.mq_maxmsg = 10L;
    mode_t mode = S_IRWXO;
    mq = mq_open(queue_name, O_WRONLY | O_CREAT, PERMS, &attr);
    if(mq < 0){
        perror("create");
        throw std::runtime_error("server queue not created");
    }
}

void Connection::deleteMQ() {
    const char * name = {"/first_q"};
    mq_unlink(name);
}

int Connection::sendData(Message & msg) {
    if(mq_send(mq, (const char *)&(msg), sizeof(msg), 1) < 0){
        perror("sending");
        throw std::runtime_error("sending problem");
    }
}
