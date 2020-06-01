#include <iostream>

#include "Connection/Connection.h"
#include <string>

int main() {
    Connection connection = Connection();
    int i = 0;
    cv::Mat pic;
    std::string filename;
    connection.initCam();
    while(true){
        filename = "../images/picture";
        pic = connection.getCameraInput();


        if(i == 100){
            i=0;
        }
        filename += std::to_string(i);
        filename += ".jpg"
        imwrite( filename, pic );

        if( cv::waitKey(10) == 27 ) break; // ESC to quit


    }
    connection.closeCam();

    return 0;
}
