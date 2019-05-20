#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

//#define EXAMPLE_2_7
//#define EXAMPLE_2_8
#define EXAMPLE_2_9

int main(int argc, char** argv)
{
	cv::Mat img_rgb, img_gray, img_cny;

	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread(argv[1]);
	if (img_rgb.empty())
	{
		cout << "Usage: example_2_7 img" << endl;
		return -1;
	}

#ifdef EXAMPLE_2_7
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
	cv::imshow("Example Gray", img_gray);

	cv::Canny(img_gray, img_cny, 10, 100, 3, true);
	cv::imshow("Example Canny", img_cny);
#endif

#ifdef EXAMPLE_2_8
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
	cv::imshow("Example Gray", img_gray);

	cv::Mat img_pyr, img_pyr2;
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gray, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2);

	cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);
	cv::imshow("Example Canny", img_cny);
#endif

#ifdef EXAMPLE_2_9
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
	cv::imshow("Example Gray", img_gray);

	cv::Mat img_pyr, img_pyr2;
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gray, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2);

	cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);

	int x = 16, y = 32;
	cv::Vec3b intensity = img_rgb.at<cv::Vec3b>(y, x);

	// Note: We could write img_rgb.at<cv::Vec3b>(x, y)[0]
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	cout << "At (x, y) = (" << x << ", " << y << 
		"): (blue, green, red) = (" << 
		(unsigned int)blue <<
		", " << (unsigned int)green << ", " <<
		(unsigned int)red << ")" << endl;

	cout << "Gray pixel there is: " << 
		(unsigned int)img_gray.at<uchar>(y, x) << endl;

	x /= 4;
	y /= 4;
	cout << "Pyramid2 pixel there is: " <<
		(unsigned int)img_pyr2.at<uchar>(y, x) << endl;
	img_cny.at<uchar>(x, y) = 128;
	cv::imshow("Example Canny", img_cny);
#endif
	cv::waitKey(0);

	return 0;
}
