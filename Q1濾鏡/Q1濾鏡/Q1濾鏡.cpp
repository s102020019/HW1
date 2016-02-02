// Q1濾鏡.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
		cv::Mat image;
		image = cv::imread("../image/robot.jpg");
		uchar *pixptr;
		float a, b, c,val;

		if (image.empty()){
			std::cout << "圖片不見了";
			system("pause");
			return 0;
		}

		std::cout << "Please give scalar for BGR respectively" << endl;
		std::cin >> a >> b >> c;
		cv::imshow("Origin", image);

		for (int i = 0; i<image.rows; i++){
			pixptr = image.ptr<uchar>(i);
			for (int j = 0; j<image.cols; j++){
				val = pixptr[0] * a;
				if (val > 255){ pixptr[0] = 255; }
				else{ pixptr[0] = pixptr[0] * a; }

				val = pixptr[1] * b;
				if (val > 255){ pixptr[1] = 255; }
				else{ pixptr[1] = pixptr[1] * b; }

				val = pixptr[2] * c;
				if (val > 255){ pixptr[2] = 255; }
				else{ pixptr[2] = pixptr[2] * c; }
		
				pixptr += 3;
			}
		}
		cv::imwrite("../image/123.png", image);
		cv::imshow("Result", image);
		cv::waitKey(0);
		return(0);
}

