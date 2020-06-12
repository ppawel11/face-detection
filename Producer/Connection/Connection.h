//
// Created by pawel on 01.06.2020.
//

#ifndef DETECTOR_CONNECTION_H
#define DETECTOR_CONNECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <mqueue.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <zconf.h>

#include "Message.h"

extern int errno;

#define PERMS 0666

class Connection {
    cv::VideoCapture cam;
    int mq;

public:
    Connection() {};

    void createMQ();
    void deleteMQ();

    int sendData(Message & msg);

};


#endif //DETECTOR_CONNECTION_H
