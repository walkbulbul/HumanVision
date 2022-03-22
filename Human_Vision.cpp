#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>


using namespace std;
using namespace cv;

float filter[7][7] = {

	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1}

};

int filtermeasure = 7;

Mat orgim;
double k, l;

Mat dst;

double total, total1, total2;






int main()

{

	orgim = imread("fit.jpg");

	Mat filtereres(orgim.rows, orgim.cols, CV_8UC3, Scalar(0, 0, 0));

	l = filtermeasure * filtermeasure;

	k = 1.0 / l;

	for (int y = 0; y < orgim.rows - filtermeasure; y++) {

		for (int x = 0; x < orgim.cols - filtermeasure; x++) {

			for (int t = 0; t < filtermeasure; t++) {

				for (int f = 0; f < filtermeasure; f++) {

					total = total + orgim.at<Vec3b>(y + t, x + f)[0] * filter[t][f] * k;

					total1 = total1 + orgim.at<Vec3b>(y + t, x + f)[1] * filter[t][f] * k;

					total2 = total2 + orgim.at <Vec3b>(y + t, x + f)[2] * filter[t][f] * k;

				}
			}
			filtereres.at<Vec3b>(y, x)[0] = total;
			filtereres.at<Vec3b>(y, x)[1] = total1;
			filtereres.at<Vec3b>(y, x)[2] = total2;

			total = 0;
			total1 = 0;
			total2 = 0;
		}

	}

	blur(orgim, dst, Size(7, 7));

	imshow("Picture", orgim);

	imshow("Ready Picture", dst);

	imshow("Function Picture", filtereres);


	waitKey(0);

	return 0;






}