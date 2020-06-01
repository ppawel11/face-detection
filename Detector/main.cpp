#include <iostream>

#include "Connection/Connection.h"
#include "Detection/Detector.h"

int main() {
    Connection connection = Connection();
    Detector detector = Detector();

    cv::Mat pic;

    connection.initCam();
    while(true){
        pic = connection.getCameraInput();
        detector.detectAndMarkFaces(pic);
        imshow("detected", pic);
        if( cv::waitKey(10) == 27 ) break; // ESC to quit
    }
    connection.closeCam();

    return 0;
}
