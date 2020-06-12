#include <iostream>
#include <opencv2/core/core.hpp>

#include "../Communication/Message.h"
#include "../Communication/MessageQueueConnection.h"
#include "Detection/Detector.h"

int main() {
    Connection * connection = new MessageQueueConnection();
    Detector detector = Detector();

    std::string recv_mq = "/producer-detector-mq";
    std::string sending_mq = "/detector-archiver-mq";

    cv::Mat pic;
    try{
        connection->open(recv_mq, O_RDONLY);
        connection->create(sending_mq);
    }catch(std::runtime_error & e){
        std::cout<<e.what()<<std::endl;
        return 1;
    }

    while(true){

        try{
            pic = connection->read();
        }catch(std::runtime_error & e){
            std::cout<<e.what()<<std::endl;
            break;
        }
        detector.detectAndMarkFaces(pic);
        Message msg(pic);
        connection->send(msg);
//        imshow("detected", pic);
        //if( cv::waitKey(10) == 27 ) break; // ESC to quit
    }

    connection->close();
    connection->remove(sending_mq);

    return 0;
}
