#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv)
{
	cv::namedWindow("Example2_10", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap;
	//sleep(3);
	if (argc == 1)
	{
		cap.open(0); // open the first camera
	}
	else
	{
		cap.open(stoi(argv[1]));
	}

	if (!cap.isOpened())
	{
		cerr << "Couldn't open capture." << endl;
		return -1;
	}

	cv::Mat frame;
	while (true)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}

		cv::imshow("Example2_10", frame);
		if (cv::waitKey(33) >= 0)
		{
			break;
		}
	}

	return 0;
}
