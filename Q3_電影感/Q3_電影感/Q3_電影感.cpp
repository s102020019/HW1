// Q3_電影感.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image;
	image = cv::imread("../image/picture2.jpg");
	uchar *pixptr;
	float a, b, c, br, avg, ct, val;

	if (image.empty()){
		std::cout << "圖片不見了";
		system("pause");
		return 0;
	}

	std::cout << "Please give scalar for BGR respectively" << endl;
	std::cin >> a >> b >> c;
	std::cout << "Please give value of Brightness br " << endl;
	std::cin >> br;
	std::cout << "Please give value of Contrast ct" << endl;
	std::cin >> ct;
	cv::imshow("Origin", image);
	//要加讓超過255的限制
	for (int i = 0; i<image.rows; i++){
		pixptr = image.ptr<uchar>(i);
		for (int j = 0; j<image.cols; j++){
			avg = (pixptr[0] + pixptr[1] + pixptr[2]) / 3;
			//讓紅色的像素變0.7倍
			if (avg < 100){
				val = pixptr[0] * a;
				if (val > 255){ pixptr[0] = 255; }
				else{ pixptr[0] = pixptr[0] * a; }

				val = pixptr[1] * b;
				if (val > 255){ pixptr[1] = 255; }
				else{ pixptr[1] = pixptr[1] * b; }

				val = pixptr[2] * c;
				if (val > 255){ pixptr[2] = 255; }
				else{ pixptr[2] = pixptr[2] * c; }
			}
			//增加亮度 如果有需要的話   val 和pixptr[k]是不同型態!??????為甚麼可以計算
			for (int k = 0; k<3; k++){
			    val = pixptr[k];
			    if (val+br > 255) { pixptr[k] = 255; }
			    else if (val+br < 0) { pixptr[k] = 0; }
			    else { pixptr[k] = pixptr[k] + br; }
			}
			//對比度調整
			
			for (int k = 0; k < 3; k++){
			    val = pixptr[k];
			    val = 128 + (val - 128)*(1 + ct);
			    if (val>255) {pixptr[k] = 255;}
			    else if (val < 0) { pixptr[k] = 0; }
			    else { pixptr[k] = 128 + (pixptr[k] - 128)*(1 + ct); }
			}
			
			pixptr += 3;
		}
	}
	//B11G105R08BR5CT01;
	cv::imwrite("../image/Result.png", image);
	cv::imshow("Result1", image);
	cv::waitKey(0);


	return 0;
}

