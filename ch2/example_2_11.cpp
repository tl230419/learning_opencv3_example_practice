#include <iostream>
#include <opencv2/opencv.hpp>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		cout << "Usage: Example_2_11 camera_id/old_video_file new_video_file" << endl;
		return -1;
	}

	cv::namedWindow("Example2_11", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

#if 1
	cv::VideoCapture cap(stoi(argv[1]));
#else
	cv::VideoCapture cap;
	cap.open(0);
#endif
	if (!cap.isOpened())
	{
		cout << "Couldn't open camera or video file" << endl;
		return -1;
	}

	double fps = cap.get(cv::CAP_PROP_FPS);
	cv::Size size(
		(int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)
	);
	
	cv::VideoWriter writer;
	writer.open(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), fps, size);

	cv::Mat logpolar_frame, bgr_frame;
	while (true)
	{
		cap >> bgr_frame;
		if (bgr_frame.empty())
		{
			break;
		}

		cv::imshow("Example2_11", bgr_frame);

		cv::logPolar(
			bgr_frame,
			logpolar_frame,
			cv::Point2f(
				bgr_frame.cols/ 2,
				bgr_frame.rows / 2
			),
			40,
			cv::WARP_FILL_OUTLIERS
		);

		cv::imshow("Log_Polar", logpolar_frame);
		writer << logpolar_frame;

		char c = cv::waitKey(10);
		if (c == 27)
		{
			break;
		}
	}

	cap.release();

	return 0;
}
