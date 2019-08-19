#include "Scharr.h"

void ScharrShow()
{
	//��0������ grad_x �� grad_y ����
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;

	//����ԭͼ
	Mat src = imread("img/14.jpg");  //����Ŀ¼��Ӧ����һ����Ϊ1.jpg���ز�ͼ

	//��2����ʾԭʼͼ 
	imshow("��ԭʼͼ��Scharr�˲���", src);

	//��3���� X�����ݶ�
	Scharr(src, grad_x, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	imshow("��Ч��ͼ�� X����Scharr", abs_grad_x);

	//��4����Y�����ݶ�
	Scharr(src, grad_y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("��Ч��ͼ��Y����Scharr", abs_grad_y);

	//��5���ϲ��ݶ�(����)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);

	//��6����ʾЧ��ͼ
	imshow("��Ч��ͼ���ϲ��ݶȺ�Scharr", dst);

	waitKey(0);
}
