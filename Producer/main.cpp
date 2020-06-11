#include <iostream>

#include "Connection/Connection.h"
#include "Connection/Message.h"
#include "Camera/Camera.h"


int main(int argc, char** argv) {

//    if ( argc < 2 )
//    {
//        printf("Specify connection mode:\n0 - mq\n1 - shm");
//        return -1;
//    }

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
