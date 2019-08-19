#include "Laplcian.h"

void Laplacianshow()
{
	//��0�������Ķ���
	Mat src, src_gray, dst, abs_dst;
	//��1������ԭʼͼ  
	src = imread("img/13.jpg");
	//��2����ʾԭʼͼ 
	imshow("��ԭʼͼ��ͼ��Laplace�任", src);
	//��3��ʹ�ø�˹�˲���������
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	//��4��ת��Ϊ�Ҷ�ͼ
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	//��5��ʹ��Laplace����
	Laplacian(src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	//��6���������ֵ���������ת����8λ
	convertScaleAbs(dst, abs_dst);
	//��7����ʾЧ��ͼ
	imshow("��Ч��ͼ��ͼ��Laplace�任", abs_dst);

	waitKey(0);

}
