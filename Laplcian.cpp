#include "Laplcian.h"

void Laplacianshow()
{
	//【0】变量的定义
	Mat src, src_gray, dst, abs_dst;
	//【1】载入原始图  
	src = imread("img/13.jpg");
	//【2】显示原始图 
	imshow("【原始图】图像Laplace变换", src);
	//【3】使用高斯滤波消除噪声
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	//【4】转换为灰度图
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	//【5】使用Laplace函数
	Laplacian(src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	//【6】计算绝对值，并将结果转换成8位
	convertScaleAbs(dst, abs_dst);
	//【7】显示效果图
	imshow("【效果图】图像Laplace变换", abs_dst);

	waitKey(0);

}
