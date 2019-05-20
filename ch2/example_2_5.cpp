#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

void example2_5(const cv::Mat& image);

int main(int argc, char** argv)
{
	cv::Mat img = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
	if (img.empty())
	{
		cout << "Usage: example_2_5 img" << endl;
		return -1;
	}

	example2_5(img);

	return 0;
}

void example2_5(const cv::Mat& image)
{
	cv::namedWindow("Example2_5-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2_5-out", cv::WINDOW_AUTOSIZE);

	cv::imshow("Example2_5-in", image);

	cv::Mat out;
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);
	cv::imshow("Example2_5-out", out);
	cv::waitKey(0);
}
