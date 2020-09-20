#include "Detection/lsd.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>

namespace ls {
struct lsd_segment{
    cv::Point p1, p2;
    int width;
};


class LSDDetection {
    const cv::Mat& image;
    image_double dImage;
   // double scale{0.0};
   // double sigma_scale{0.0};
public:
    LSDDetection(const cv::Mat& image): image(image){}//{dImage = std::move(new_image_double(image.cols, image.rows));}
    std::vector<lsd_segment> detectLines();


};
std::shared_ptr<LSDDetection> createLSDDetector(const cv::Mat& image);
}
