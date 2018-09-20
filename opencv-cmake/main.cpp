#include <iostream>
#include "opencv2/core/core.hpp"


int main()
{
    cv::Mat M(2, 2, CV_8UC3, cv::Scalar(0, 0, 255));
    std::cout << "M = " << std::endl << M << std::endl << std::endl;

    M.create(4, 4, CV_8UC(2));
    std::cout << "M = " << std::endl << M << std::endl << std::endl;

    return 0;

}