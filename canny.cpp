#include"canny.h"


void cannyShow() {
	Mat srcImage = imread("img/11.jpg");
	Mat srcImage1 = srcImage.clone();

	//显示原图
	imshow("原始图片", srcImage);

	//----------------------------------------------------------------------------------
	//	一、最简单的canny用法，拿到原图后直接用。
	//	注意：此方法在OpenCV2中可用，在OpenCV3中已失效
	//----------------------------------------------------------------------------------
	//Canny( srcImage, srcImage, 150, 100,3 );
	//imshow("【效果图】Canny边缘检测", srcImage); 

	//----------------------------------------------------------------------------------
	//	二、高阶的canny用法，转成灰度图，降噪，用canny，最后将得到的边缘作为掩码，拷贝原图到效果图上，得到彩色的边缘图
	//----------------------------------------------------------------------------------
	Mat dstImage, edge, grayImage;
	dstImage.create(srcImage.size(), srcImage.type());//【1】创建与原图大小，类型相同的空白矩阵(图片)

	cvtColor(srcImage1, grayImage, COLOR_BGR2GRAY);//【2】将原图转化为灰度图

	blur(grayImage, edge, Size(3, 3));//【3】使用 3x3内核来降噪
	Canny(edge, edge, 3, 9, 3);// 【4】运行Canny算子
	imshow("edge", edge);
	dstImage = Scalar::all(0);//【5】 将g_dstImage内的所有元素设置为0
	//【6】使用Canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图g_srcImage拷到目标图g_dstImage中
	srcImage1.copyTo(dstImage, edge);
	//【7】显示效果图 
	imshow("【效果图】Canny边缘检测2", dstImage);


	waitKey(0);


}