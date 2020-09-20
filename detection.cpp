#include "detection.hpp"
using namespace ls;

std::shared_ptr<LSDDetection> ls::createLSDDetector(const cv::Mat& image) {
    return std::shared_ptr<LSDDetection>(new LSDDetection(image));
}
std::vector<lsd_segment> LSDDetection::detectLines() {
    cv::Mat tmp, img_gray;
//   std::vector<std::pair<cv::Point2f, cv::Point2f>> segment;
    std::vector<lsd_segment> segment;
    cv::cvtColor(image, tmp, cv::COLOR_BGR2GRAY);
    tmp.convertTo(img_gray, CV_64FC1);
    dImage = std::move(new_image_double(img_gray.cols, img_gray.rows));
    dImage->data = img_gray.ptr<double>(0);
    ntuple_list ntl = lsd(dImage);

    cv::Point pt1, pt2;
    for (int j = 0; j != ntl->size; ++j) {
        lsd_segment seg;
        pt1.x = int(ntl->values[0 + j*ntl->dim]);
        pt1.y = int(ntl->values[1 + j*ntl->dim]);
        pt2.x = int(ntl->values[2 + j*ntl->dim]);
        pt2.y = int(ntl->values[3 + j*ntl->dim]);
//        segment.push_back({pt1,pt2});
        int width = int(ntl->values[4+j*ntl->dim]);
        seg.p1 = pt1;
        seg.p2 = pt2;
        seg.width = width;
        segment.push_back(seg);

    }
    free_ntuple_list(ntl);

    return segment;
}

