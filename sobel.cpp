#include"sobel.h"

void sobelShow() {
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;

	//【1】载入原始图  
	Mat src = imread("img/12.jpg");

	//【2】显示原始图 
	imshow("【原始图】sobel边缘检测", src);

	//【3】求 X方向梯度
	Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);//转化为绝对值
	imshow("【效果图】 X方向Sobel", abs_grad_x);

	//【4】求Y方向梯度
	Sobel(src, grad_y, CV_16S, 0, 1, 3, 11, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("【效果图】Y方向Sobel", abs_grad_y);

	//【5】合并梯度(近似)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);

	imshow("【效果图】综合Sobel", dst);
	waitKey(0);
	return ;

}