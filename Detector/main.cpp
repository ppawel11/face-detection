#include <iostream>
#include <fstream>
#include <chrono>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Connection/Connection.h"
#include "Detection/Detector.h"

using namespace std::chrono;

int main() {
    Connection connection = Connection();
    Detector detector = Detector();

    std::ofstream logFile;

    cv::Mat pic;
    try{
        connection.openMQ();
    }catch(std::runtime_error & e){
        std::cout<<e.what()<<std::endl;
        return 1;
    }

    nanoseconds startTimestamp;
    nanoseconds endTimestamp;

    while(true){
        logFile.open("log3.txt",std::ios::app);

        try{
            Message msg = connection.read();

            startTimestamp = msg.timestamp;
            endTimestamp = duration_cast< nanoseconds >(
                    system_clock::now().time_since_epoch()
            );

            pic = msg.produceFrame();
        }catch(std::runtime_error & e){
            std::cout<<e.what()<<std::endl;
            break;
        }


        detector.detectAndMarkFaces(pic);
        imshow("detected", pic);
        if( cv::waitKey(10) == 27 ) break; // ESC to quit

        logFile  << endTimestamp.count() -  startTimestamp.count() << std::endl;
        logFile.close();
    }

    connection.closeMQ();
    return 0;
}
