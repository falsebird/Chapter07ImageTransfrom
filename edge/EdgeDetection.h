#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
bool EdgeDetectionMain();

static void on_Canny(int, void*);//Canny��Ե��ⴰ�ڹ������Ļص�����
static void on_Sobel(int, void*);//Sobel��Ե��ⴰ�ڹ������Ļص�����
void Scharr();//��װ��Scharr��Ե�����ش���ĺ���
