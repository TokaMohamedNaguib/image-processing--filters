// sobel_filter.cpp : Defines the entry point for the console application.
//
/**/
#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;


void sobel_filter_greyscale() {
	Mat img = imread("image-2.png", CV_LOAD_IMAGE_GRAYSCALE);
	Mat rgbchannel[3];

	
	
	int rows = img.rows;
	int cols = img.cols;
	Mat outputimage = img.clone();

	
	int r, c;
	int gx, gy;
	for (r = 1; r < rows - 1; r++)
	{
	for (c = 1; c < cols - 1; c++)
	{

	gx = -img.at<uchar>(r-1, c-1)+ img.at<uchar>(r-1, c+1)+ -2 * img.at<uchar>(r, c-1) + 2 * img.at<uchar>(r, c+1)
	+ -img.at<uchar>(r+1, c-1) + img.at<uchar>(r+1, c+1);
	gy = -img.at<uchar>(r - 1, c - 1) -2* img.at<uchar>(r - 1, c ) + - img.at<uchar>(r-1, c + 1) +   img.at<uchar>(r+1, c - 1)
	+ 2*img.at<uchar>(r + 1, c ) + img.at<uchar>(r + 1, c + 1);

	outputimage.at<uchar>(r,c) = sqrt((float)(gx)*(float)(gx)+(float)(gy)*(float)(gy));



	}
	}
	namedWindow("final");
	imshow("final", outputimage);

	namedWindow("initial");
	imshow("initial", img);
	waitKey(0);
}
void sobel_filter_color_image() {
	Mat img = imread("image-2.png", CV_LOAD_IMAGE_COLOR);
	Mat rgbchannel[3];

	
	split(img , rgbchannel);
	
	Mat rgbchanneloutput[3];
	split(img, rgbchanneloutput);
	
	
	int rows = img.rows;
	int cols = img.cols;
	Mat outputimage=img.clone();

	int r, c;
	

	int gx0 ,gx1,gx2, gy0,gy1,gy2 ;
	

	for (r = 1; r < rows - 1; r++)
	{
	for (c = 1; c < cols - 1; c++)
	{

	gx0 = -rgbchannel[0].at<uchar>(r-1, c-1)+ rgbchannel[0].at<uchar>(r-1, c+1)+ -2 * rgbchannel[0].at<uchar>(r, c-1) + 2 * rgbchannel[0].at<uchar>(r, c+1)
	+ -rgbchannel[0].at<uchar>(r+1, c-1) + rgbchannel[0].at<uchar>(r+1, c+1);
	gy0 = -rgbchannel[0].at<uchar>(r - 1, c - 1) -2* rgbchannel[0].at<uchar>(r - 1, c ) + -rgbchannel[0].at<uchar>(r-1, c + 1) + rgbchannel[0].at<uchar>(r+1, c - 1)
	+ 2* rgbchannel[0].at<uchar>(r + 1, c ) + rgbchannel[0].at<uchar>(r + 1, c + 1);

	gx1 = -rgbchannel[1].at<uchar>(r - 1, c - 1) + rgbchannel[1].at<uchar>(r - 1, c + 1) + -2 * rgbchannel[1].at<uchar>(r, c - 1) + 2 * rgbchannel[1].at<uchar>(r, c + 1)
	+ -rgbchannel[1].at<uchar>(r + 1, c - 1) + rgbchannel[1].at<uchar>(r + 1, c + 1);
	gy1 = -rgbchannel[1].at<uchar>(r - 1, c - 1) - 2 * rgbchannel[1].at<uchar>(r - 1, c) + -rgbchannel[1].at<uchar>(r - 1, c + 1) + rgbchannel[1].at<uchar>(r + 1, c - 1)
	+ 2 * rgbchannel[1].at<uchar>(r + 1, c) + rgbchannel[1].at<uchar>(r + 1, c + 1);


	gx2 = -rgbchannel[2].at<uchar>(r-1, c-1)+ rgbchannel[2].at<uchar>(r-1, c+1)+ -2 * rgbchannel[2].at<uchar>(r, c-1) + 2 * rgbchannel[2].at<uchar>(r, c+1)
	+ -rgbchannel[2].at<uchar>(r+1, c-1) + rgbchannel[2].at<uchar>(r+1, c+1);
	gy2 = -rgbchannel[2].at<uchar>(r - 1, c - 1) -2* rgbchannel[2].at<uchar>(r - 1, c ) + -rgbchannel[2].at<uchar>(r-1, c + 1) + rgbchannel[2].at<uchar>(r+1, c - 1)
	+ 2* rgbchannel[2].at<uchar>(r + 1, c ) + rgbchannel[2].at<uchar>(r + 1, c + 1);


	rgbchanneloutput[0].at<uchar>(r, c) = sqrt((float)(gx0)*(float)(gx0)+(float)(gy0)*(float)(gy0));
	rgbchanneloutput[1].at<uchar>(r, c) = sqrt((float)(gx1)*(float)(gx1)+(float)(gy1)*(float)(gy1));
	rgbchanneloutput[2].at<uchar>(r, c) = sqrt((float)(gx2)*(float)(gx2)+(float)(gy2)*(float)(gy2));

	
	


	}
	}
	merge(rgbchanneloutput, 3, outputimage);


	
	namedWindow("final");
	imshow("final", outputimage);

	namedWindow("initial");
	imshow("initial", img);
	waitKey(0);
	


}
void filter_orange_color() {
	Mat img = imread("image-2.png", CV_LOAD_IMAGE_COLOR);
	
	int rows = img.rows;
	int cols = img.cols;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{

			Vec3b color = img.at<Vec3b>(Point(c, r));

			if (color[1] == 127) {
				
				color[0] = 0;
				color[1] = 0;
				color[2] = 0;
				img.at<Vec3b>(Point(c, r)) = color;
			}

		}
	}
	namedWindow("initial");
	imshow("initial", img);
	waitKey(0);
}
int main()
{
	
	int type=0;
	while (1) {
		cout << "please enter (1) if you want to test sobel filter on grey images or (2)  if you want to test sobel filter on color images or (3) if you want to test filter orange";
		cin >> type;
		if (type == 1) {
			sobel_filter_greyscale();
		}
		else if (type == 2) {
			sobel_filter_color_image();
		}
		else if(type==3){
			filter_orange_color();
		}
		else {
			cout << "you enter a wrong number please try again";
		}
	}

	return 0;
}

