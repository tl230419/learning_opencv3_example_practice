// Pyramid L-K optical flow example
//
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static const int MAX_CORNERS = 1000;

void help(char** argv)
{
	cout << "Call: " << argv[0] << "[image1] [image2]" << endl;
	cout << "Demonstrates Pyramid Lucas-Kanade optical flow." << endl;
}

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		help(argv);
		exit(-1);
	}

	// Initialize, load two images from the file system, and
	// allocate the images and other structures we will need
	// for results.
	//
	Mat imgA =  imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	Mat imgB =  imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
	Size img_size = imgA.size();
	int win_size = 10;
	Mat imgC = imread(argv[2], CV_LOAD_IMAGE_UNCHANGED);

	// The first thing we need to do is get the features we want to track.
	//
	vector< Point2f> cornersA, cornersB;
	const int MAX_CORNERS = 500;
	goodFeaturesToTrack(
		imgA,
		cornersA,
		MAX_CORNERS,
		0.01,
		5,
		noArray(),
		3,
		false,
		0.04
	);
	 cornerSubPix(
		imgA,
		cornersA,
		Size(win_size, win_size),
		Size(-1, -1),
		TermCriteria(
			TermCriteria::MAX_ITER | TermCriteria::EPS,
			20,
			0.03
		)
	);

	// Call the lucas Kanade algorithm
	//
	vector<uchar> features_found;
	calcOpticalFlowPyrLK(
		imgA,
		imgB,
		cornersA,
		cornersB,
		features_found,
		noArray(),
		Size(win_size * 2 + 1, win_size * 2 + 1),
		5,
		TermCriteria(
			TermCriteria::MAX_ITER | TermCriteria::EPS,
			20,
			0.3
		)
	);

	// Now make some image of what we are looking at:
	// Note that if you want to track cornersB further, i.e.
	// pass them as input to tne next calcOpticalFlowPyrLK,
	// you would need to "compress" the vectors, i.e., exclude point for which
	// features_found[i] == false.
	for (int i = 0; i < (int)cornersA.size(); i++)
	{
		if (!features_found[i])
			continue;
		//line(imgC, cornersA[i], cornersB[i], Scalar(0, 255, 0), 2, CV_AA);
		line(imgC, cornersA[i], cornersB[i], Scalar(0, 255, 0), 2, LINE_AA);
	}
	imshow("ImageA", imgA);
	imshow("ImageB", imgB);
	imshow("LK Optical Flow Example", imgC);
	waitKey(0);

	return 0;
}
