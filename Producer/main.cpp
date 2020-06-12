#include <iostream>
#include <fstream>
#include <sched.h>
#include <chrono>

#include "Connection/Connection.h"
#include "Connection/Message.h"
#include "Camera/Camera.h"

using namespace std::chrono;

int main(int argc, char** argv) {

    Connection connection = Connection();
    Camera camera = Camera();
    cv::Mat frame;
    std::ofstream logFile;

    sched_param params;
    params.sched_priority = 1;
    sched_setscheduler(0,SCHED_DEADLINE,&params );

    try {
        camera.init();
        connection.createMQ();


    }catch(std::runtime_error & e){
        std::cout<<e.what()<<std::endl;
        return 1;
    }

    while(true){
        logFile.open("SCHED_DEADLINE_1.txt",std::ios::app);

        frame = camera.read();
        Message msg(frame);

        try{
            connection.sendData(msg);
        }catch(std::runtime_error & e){
            std::cout<<e.what()<<std::endl;
            break;
        }

        logFile  << msg.timestamp.count() << std::endl;
        logFile.close();
    }

    camera.close();
    connection.deleteMQ();

    return 0;
}
