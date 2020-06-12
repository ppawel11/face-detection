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

    try {
        camera.init();
        connection.createMQ();


    }catch(std::runtime_error & e){
        std::cout<<e.what()<<std::endl;
        return 1;
    }

    while(true){

        frame = camera.read();
        Message msg(frame);

        try{
            connection.sendData(msg);
        }catch(std::runtime_error & e){
            std::cout<<e.what()<<std::endl;
            break;
        }

    }

    camera.close();
    connection.deleteMQ();

    return 0;
}
