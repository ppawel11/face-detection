#include <iostream>

#include "../Communication/MessageQueueConnection.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <string>

int main() {

    Connection * connection = new MessageQueueConnection();
    cv::Mat frame;
    std::string mq_name = "/detector-archiver-mq";
    try{
        connection->open(mq_name, O_RDONLY);
    }catch(std::runtime_error & e){
        std::cout<<e.what();
        return 1;
    }
    while(true){
        try{
            frame = connection->read();
        }catch(std::runtime_error & e){
            std::cout<<e.what();
            break;
        }
        std::cout<<frame.cols<<std::endl;
        cv::imshow("archived", frame);
        if( cv::waitKey(10) == 27 ) break;
        cv::imwrite("../../Archiver/photos/myphoto.png", frame);
    }

    connection->close();
    return 0;
}
