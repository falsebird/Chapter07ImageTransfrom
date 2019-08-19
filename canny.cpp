#include"canny.h"


void cannyShow() {
	Mat srcImage = imread("img/11.jpg");
	Mat srcImage1 = srcImage.clone();

	//��ʾԭͼ
	imshow("ԭʼͼƬ", srcImage);

	//----------------------------------------------------------------------------------
	//	һ����򵥵�canny�÷����õ�ԭͼ��ֱ���á�
	//	ע�⣺�˷�����OpenCV2�п��ã���OpenCV3����ʧЧ
	//----------------------------------------------------------------------------------
	//Canny( srcImage, srcImage, 150, 100,3 );
	//imshow("��Ч��ͼ��Canny��Ե���", srcImage); 

	//----------------------------------------------------------------------------------
	//	�����߽׵�canny�÷���ת�ɻҶ�ͼ�����룬��canny����󽫵õ��ı�Ե��Ϊ���룬����ԭͼ��Ч��ͼ�ϣ��õ���ɫ�ı�Եͼ
	//----------------------------------------------------------------------------------
	Mat dstImage, edge, grayImage;
	dstImage.create(srcImage.size(), srcImage.type());//��1��������ԭͼ��С��������ͬ�Ŀհ׾���(ͼƬ)

	cvtColor(srcImage1, grayImage, COLOR_BGR2GRAY);//��2����ԭͼת��Ϊ�Ҷ�ͼ

	blur(grayImage, edge, Size(3, 3));//��3��ʹ�� 3x3�ں�������
	Canny(edge, edge, 3, 9, 3);// ��4������Canny����
	imshow("edge", edge);
	dstImage = Scalar::all(0);//��5�� ��g_dstImage�ڵ�����Ԫ������Ϊ0
	//��6��ʹ��Canny��������ı�Եͼg_cannyDetectedEdges��Ϊ���룬����ԭͼg_srcImage����Ŀ��ͼg_dstImage��
	srcImage1.copyTo(dstImage, edge);
	//��7����ʾЧ��ͼ 
	imshow("��Ч��ͼ��Canny��Ե���2", dstImage);


	waitKey(0);


}