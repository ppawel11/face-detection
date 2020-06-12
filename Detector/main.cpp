#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Connection/Connection.h"
#include "Detection/Detector.h"

int main() {
    Connection connection = Connection();
    Detector detector = Detector();

    cv::Mat pic;
    try{
        connection.openReceivingMQ();
        connection.createSendingMQ();
    }catch(std::runtime_error & e){
        std::cout<<e.what()<<std::endl;
        return 1;
    }

    while(true){
        try{
            pic = connection.read();
        }catch(std::runtime_error & e){
            std::cout<<e.what()<<std::endl;
            break;
        }
        detector.detectAndMarkFaces(pic);
        Message msg(pic);
        connection.sendData(msg);
//        imshow("detected", pic);
        //if( cv::waitKey(10) == 27 ) break; // ESC to quit
    }

    connection.closeReceivingMQ();
    connection.deleteSendingMQ();

    return 0;
}
