#include <cstdlib>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void detectAndDisplay(cv::Mat frame);

int main(int argc, char **argv){

    if( argc < 2 ){
        std::cout << "Usage: main <image filename>" << std::endl;
        return -1;
    }
    
    cv::Mat frame = cv::imread(argv[1]);

    cv::CascadeClassifier face_cascade;
    cv::CascadeClassifier eye_cascade;

    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;
    

    // load the cascades
    if( !face_cascade.load("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml") ){
        std::cout << "Could not load face cascade classifier." << std::endl;
        return -1;
    } else {
        std::clog << "face cascade loaded" << std::endl;
    }
    if( !eye_cascade.load("/usr/local/share/opencv4/haarcascades/haarcascade_eye_tree_eyeglasses.xml") ){
        std::cout << "Could not load face cascade classifier." << std::endl;
        return -1;
    } else {
        std::clog << "eye cascade loaded" << std::endl;
    }


    // check image failure
    if( frame.empty() ){
        std::cout << "Could not open image." << std::endl;
        return -1;
    }
    
    // detection of faces
    cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(frame_gray, frame_gray);

    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30,30));


    for( size_t i = 0; i < faces.size(); i++ ){
        cv::Point center(faces[i].x + faces[i].width/2, faces[i].y+faces[i].height/2);
        cv::ellipse(frame, center, cv::Size(faces[i].width/2, faces[i].height/2), 0, 0, 360, cv::Scalar(255, 0, 255), 4, 8, 0);
        cv::Mat faceROI = frame_gray(faces[i]);
    }


    std::string windowName = "Dog";

    cv::namedWindow(windowName);

    cv::imshow(windowName, frame);

    cv::waitKey(0);

    cv::destroyWindow(windowName);    

    return 0;
}


void detectAndDisplay(cv::Mat frame){
    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;
    
    cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(frame_gray, frame_gray);
}
