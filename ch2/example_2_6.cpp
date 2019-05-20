#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char** argv)
{
	cv::Mat img1, img2;

	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);

	img1 = cv::imread(argv[1]);
	if (img1.empty())
	{
		cout << "Usage: example_2_6 img" << endl;
		return -1;
	}

	cv::imshow("Example1", img1);

	cv::pyrDown(img1, img2);
	cv::imshow("Example2", img2);

	cv::waitKey(0);

	return 0;
}
