#include"sobel.h"

void sobelShow() {
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;

	//��1������ԭʼͼ  
	Mat src = imread("img/12.jpg");

	//��2����ʾԭʼͼ 
	imshow("��ԭʼͼ��sobel��Ե���", src);

	//��3���� X�����ݶ�
	Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);//ת��Ϊ����ֵ
	imshow("��Ч��ͼ�� X����Sobel", abs_grad_x);

	//��4����Y�����ݶ�
	Sobel(src, grad_y, CV_16S, 0, 1, 3, 11, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("��Ч��ͼ��Y����Sobel", abs_grad_y);

	//��5���ϲ��ݶ�(����)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);

	imshow("��Ч��ͼ���ۺ�Sobel", dst);
	waitKey(0);
	return ;

}