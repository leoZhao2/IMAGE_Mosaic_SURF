#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include<Windows.h>
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

#include <iostream>
using namespace std;
using namespace cv;

bool try_use_gpu = false;
vector<Mat> imgs;
string result_name = "47.png";

int main()
{
	Mat img1 = imread("45.png");
	Mat img2 = imread("46.png");
	imgs.push_back(img1);
	imgs.push_back(img2);
	Mat pano;
	Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
	Stitcher::Status status = stitcher.stitch(imgs, pano);
	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << status << endl;
		return -1;
	}
	namedWindow(result_name);
	imshow(result_name, pano);
	imwrite(result_name, pano);
	waitKey();
	return 0;
}