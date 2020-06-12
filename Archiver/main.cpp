#include <iostream>

#include "Connection/Connection.h"
#include <string>

int main() {

    Connection connection = Connection();
    cv::Mat frame;

    try{
        connection.openReceivingMQ();
    }catch(std::runtime_error & e){
        std::cout<<e.what();
        return 1;
    }

    while(true){
        try{
            frame = connection.receiveData();
        }catch(std::runtime_error & e){
            std::cout<<e.what();
            break;
        }
        std::cout<<frame.cols<<std::endl;
        cv::imshow("archived", frame);
        if( cv::waitKey(10) == 27 ) break;
        cv::imwrite("../photos/myphoto.png", frame);
//        cv::waitKey(0);
    }

    connection.closeReceivingMQ();
    return 0;
}
