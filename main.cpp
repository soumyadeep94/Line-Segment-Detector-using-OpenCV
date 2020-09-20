#include <iostream>
#include <opencv2/opencv.hpp>
#include "detection.hpp"

using namespace std;
using namespace ls;
int main()
{
    const cv::Mat img = cv::imread("/home/soumyadeep/test.jpg");
    cv::Mat result = img.clone();
    std::cout<<img.size()<<std::endl;
    auto lsd = createLSDDetector(img);
    auto segments = lsd->detectLines();

    
    cv::Point pt1, pt2;
    for (int j = 0; j < segments.size(); ++j) {
    	pt1 = segments[j].p1;
    	pt2 = segments[j].p2;

    	cv::line(result, pt1, pt2, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
    }

    cv::imshow("image", img);
    cv::imshow("result_img", result);
    cv::waitKey();
    return 0;
}
