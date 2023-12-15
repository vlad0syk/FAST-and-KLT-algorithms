#include <opencv2/opencv.hpp>

std::vector<cv::KeyPoint> detectFAST(const cv::Mat& image, int threshold) {
    std::vector<cv::KeyPoint> keypoints;

    // ������������� cv::Ptr ��� ��������� ��'���� ��������� FAST
    cv::Ptr<cv::FastFeatureDetector> detector = cv::FastFeatureDetector::create(threshold);

    // ����������� �������� �� ����������
    detector->detect(image, keypoints);

    return keypoints;
}

int main() {
    // ������� ����������
    cv::Mat image = cv::imread("C:\\Users\\Acer\\OneDrive\\Desktop\\1.jpg", cv::IMREAD_GRAYSCALE);


    if (image.empty()) {
        std::cerr << "Unable to read the image." << std::endl;
        return -1;
    }

    // ������������ ���� ��� ��������� FAST
    int threshold = 50;

    // ��������� ������ �����
    std::vector<cv::KeyPoint> keypoints = detectFAST(image, threshold);

    // ³�������� ���������
    cv::Mat imageWithKeypoints;
    cv::drawKeypoints(image, keypoints, imageWithKeypoints, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    // ³��������� ���������� � ��������� �������
    cv::imshow("FAST Keypoints", imageWithKeypoints);
    cv::waitKey(0);

    return 0;
}