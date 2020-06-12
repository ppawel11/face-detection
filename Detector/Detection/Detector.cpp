//
// Created by pawel on 01.06.2020.
//

#include "Detector.h"

Detector::Detector() {
    if( !face_classifier.load( "../../Detector/Detection/haarcascade_frontalface_alt.xml" ) )
        throw std::runtime_error("Error loading face cascade");
}

void Detector::detectAndMarkFaces(cv::Mat frame) {
    std::vector<cv::Rect> faces = detect(frame);
    markDetectedFaces(frame, faces);
}

std::vector<cv::Rect> Detector::detect(cv::Mat frame) {
    std::vector<cv::Rect> faces;
    face_classifier.detectMultiScale( frame, faces );
    return faces;
}

void Detector::markDetectedFaces(cv::Mat frame, const std::vector<cv::Rect>& faces) {
    for ( const cv::Rect& face : faces ){
        rectangle( frame, face, cv::Scalar( 100, 100, 0 ), 2 );
    }
}
