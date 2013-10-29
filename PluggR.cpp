#include <opencv2/highgui/highgui.hpp>

void makeImage(const char* text)
{
    cv::Mat image(124, 124, CV_8UC1);
    cv::imwrite(text, image);
}
