#include <iostream>

#include "../Communication/Message.h"
#include "../Communication/MessageQueueConnection.h"

#include "Camera/Camera.h"


int main(int argc, char** argv) {

//    if ( argc < 2 )
//    {
//        printf("Specify connection mode:\n0 - mq\n1 - shm");
//        return -1;
//    }

    Connection * connection = new MessageQueueConnection();
    Camera camera = Camera();
    cv::Mat frame;

    std::string output_queue = "/producer-detector-mq";

    try {
        camera.init();
        connection->create(output_queue);
    }catch(std::runtime_error & e){
        std::cout<<e.what()<<std::endl;
        return 1;
    }
    int i = 0;
    while(true){
        std::cout<<i++<<std::endl;
        frame = camera.read();
        cv::Mat resized = cv::Mat();
        cv::resize(frame, resized, cv::Size(90, 90), 0, 0, CV_INTER_CUBIC);
        Message msg(resized);
        try{
            connection->send(msg);
        }catch(std::runtime_error & e){
            std::cout<<e.what()<<std::endl;
            break;
        }
    }

    camera.close();
    connection->remove(output_queue);

    return 0;
}
