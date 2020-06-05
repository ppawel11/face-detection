#include <iostream>

#include "Connection/Connection.h"

int main(int argc, char** argv) {

    if ( argc < 2 )
    {
        printf("Invalid amount of arguments");
        return -1;
    }

    Connection connection = Connection();
    cv::Mat pic;

    if(argv[1] == "c"){
        connection.initCam();

        while(true){
            pic = connection.getCameraInput();
            imshow("detected", pic);
            if( cv::waitKey(10) == 27 ) break; // ESC to quit
        }

        connection.closeCam();
    }

    else {

        while (true) {
            pic = connection.readFromFile("./picture_examples/lena.png");
            imshow("detected", pic);
            if (cv::waitKey(10) == 27) break; // ESC to quit
        }
    }

    return 0;
}
