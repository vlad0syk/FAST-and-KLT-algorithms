#include <opencv2/opencv.hpp>

int main() {
    // Read a video stream or video file
    cv::VideoCapture cap("C:\\Users\\Acer\\OneDrive\\Desktop\\4.gif"); // 0 for the webcam, or you can specify the path to the video file

    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to open the video source." << std::endl;
        return -1;
    }

    cv::Mat frame;
    cv::Mat gray;

    // Reading the first frame to get the dimensions
    cap >> frame;

    // Convert a color frame to grayscale
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // Defining the Angle Tracker
    std::vector<cv::Point2f> corners;
    cv::goodFeaturesToTrack(gray, corners, 100, 0.01, 10);

    // Let's display the found angles in the original image
    for (const auto& corner : corners) {
        cv::circle(frame, corner, 5, cv::Scalar(0, 255, 0), -1);
    }

    // Display the Output Frame with Corners
    cv::imshow("Corners", frame);

    // Waiting for the key to be pressed before exiting
    cv::waitKey(0);

    return 0;
}
