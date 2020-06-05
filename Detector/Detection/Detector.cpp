//
// Created by pawel on 01.06.2020.
//

#include "Detector.h"

Detector::Detector() {
    if( !face_classifier.load( "./Detection/haarcascade_frontalface_alt.xml" ) )
        throw std::runtime_error("Error loading face cascade");
}

void Detector::detectAndMarkFaces(cv::Mat frame) {
    cv::Mat clean = prepareForDetection(frame);
    std::vector<cv::Rect> faces = detect(clean);
    markDetectedFaces(frame, faces);
}

cv::Mat Detector::prepareForDetection(const cv::Mat& frame) {
    cv::Mat frame_gray;
    cvtColor( frame, frame_gray, cv::COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    return frame_gray;
}

std::vector<cv::Rect> Detector::detect(cv::Mat frame) {
    std::vector<cv::Rect> faces;
    face_classifier.detectMultiScale( frame, faces );
    return faces;
}

void Detector::markDetectedFaces(cv::Mat frame, const std::vector<cv::Rect>& faces) {
    for ( const cv::Rect& face : faces ){
        rectangle( frame, face, cv::Scalar( 100, 100, 0 ), 4 );
    }
}
