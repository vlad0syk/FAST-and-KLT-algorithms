#include <opencv2/opencv.hpp>

std::vector<cv::KeyPoint> detectFAST(const cv::Mat& image, int threshold) {
    std::vector<cv::KeyPoint> keypoints;

    // Use cv::P tr to create a FAST detector object
    cv::Ptr<cv::FastFeatureDetector> detector = cv::FastFeatureDetector::create(threshold);

    // Apply the detector to the image
    detector->detect(image, keypoints);

    return keypoints;
}

int main() {
    // Reading the image
    cv::Mat image = cv::imread("C:\\Users\\Acer\\OneDrive\\Desktop\\1.jpg", cv::IMREAD_GRAYSCALE);


    if (image.empty()) {
        std::cerr << "Unable to read the image." << std::endl;
        return -1;
    }

    // Setting the threshold for the FAST detector
    int threshold = 50;

    // Detecting key points
    std::vector<cv::KeyPoint> keypoints = detectFAST(image, threshold);

    // Visualize the result
    cv::Mat imageWithKeypoints;
    cv::drawKeypoints(image, keypoints, imageWithKeypoints, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    // Display images with key points
    cv::imshow("FAST Keypoints", imageWithKeypoints);
    cv::waitKey(0);

    return 0;
}