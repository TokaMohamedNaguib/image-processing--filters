
/*
#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	Mat img = imread("image-2.png", CV_LOAD_IMAGE_GRAYSCALE);
	uint8_t *myData = img.data;
	cout << myData[0];
	
	/*int rows = img.rows;
	int cols = img.cols;
	Mat outputimage = img.clone();
	int r, c;
	int gx, gy;
	for (r = 1; r < rows - 1; r++)
	{
		for (c = 1; c < cols - 1; c++)
		{

			gx = -img.at<uchar>(r - 1, c - 1) + img.at<uchar>(r - 1, c + 1) + -2 * img.at<uchar>(r, c - 1) + 2 * img.at<uchar>(r, c + 1)
				+ -img.at<uchar>(r + 1, c - 1) + img.at<uchar>(r + 1, c + 1);
			gy = -img.at<uchar>(r - 1, c - 1) - 2 * img.at<uchar>(r - 1, c) + -img.at<uchar>(r - 1, c + 1) + img.at<uchar>(r + 1, c - 1)
				+ 2 * img.at<uchar>(r + 1, c) + img.at<uchar>(r + 1, c + 1);

			outputimage.at<uchar>(r, c) = sqrt((float)(gx)*(float)(gx)+(float)(gy)*(float)(gy));



		}
	}
	namedWindow("final");
	imshow("final", outputimage);

	namedWindow("initial");
	imshow("initial", img);*/
/*	waitKey(0);


	return 0;
}

*/