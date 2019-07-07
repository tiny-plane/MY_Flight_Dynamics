#include "BpNet.h"

using namespace std;


BpNet::BpNet() {
	error = 1.0;
	e = 0.0;
	rate_w = 0.1; //Ȩֵѧϰ�ʣ������--������)
	rate_w1 = 0.1; //Ȩֵѧϰ�� (������--�����)
	rate_b1 = 0.1; //�����㷧ֵѧϰ��
	rate_b2 = 0.1; //����㷧ֵѧϰ�� 
}
BpNet::~BpNet()
{
}
//����[low, high)֮��������
double randval(double low, double high)
{
	double val;
	val = ((double)(rand() % RAND_MAX) / (double)RAND_MAX) * (high - low) + low;
	return(val);
}
void winit(double w[], int n) //Ȩֵ��ʼ�� 
{
	for (int i = 0; i < n; i++)
		w[i] = randval(-0.01, 0.01);
}
//��ʼ�� 
void BpNet::init()
{
	winit((double*)w, innode * hidenode);
	winit((double*)w1, hidenode * outnode);
	winit(b1, hidenode);
	winit(b2, outnode);
}
//ѵ��
void BpNet::train(double p[trainsample][innode], double t[trainsample][outnode])
{
	double pp[hidenode]; 	//��������У����� 
	double qq[outnode]; //ϣ�����ֵ��ʵ�����ֵ��ƫ�� 
	double yd[outnode]; //ϣ�����ֵ 
	double x[innode]; //��������
	double x1[hidenode]; //�������״ֵ̬
	double x2[outnode]; //������״ֵ̬ 
	double o1[hidenode]; //�����㼤��ֵ
	double o2[hidenode]; //����㼤��ֵ

	for (int isamp = 0; isamp < trainsample; isamp++) //ѭ��ѵ��һ����Ʒ 
	{
		int i, j, k;
		for (i = 0; i < innode; i++)
			x[i] = p[isamp][i]; //���������
		for (i = 0; i < outnode; i++)
			yd[i] = t[isamp][i]; //ϣ�����������
//���򴫲� 
							 //����ÿ����Ʒ������������׼
		for (j = 0; j < hidenode; j++)
		{
			o1[j] = 0.0;
			for (i = 0; i < innode; i++)
				o1[j] += w[i][j] * x[i]; //���������Ԫ���뼤��ֵ
			x1[j] = 1.0 / (1.0 + exp(-o1[j] - b1[j])); //���������Ԫ����� 
		}
		for (k = 0; k < outnode; k++)
		{
			o2[k] = 0.0;
			for (int j = 0; j < hidenode; j++)
				o2[k] += w1[j][k] * x1[j]; //��������Ԫ���뼤��ֵ 
			x2[k] = 1.0 / (1.0 + exp(-o2[k] - b2[k])); //��������Ԫ��� 
		}

		//���򴫲� 
		for (k = 0; k < outnode; k++) //����������ÿ�������Ԫ����������������Ȩֵ
		{
			qq[k] = (yd[k] - x2[k]) * x2[k] * (1 - x2[k]); //ϣ�������ʵ�������ƫ�� 
			for (j = 0; j < hidenode; j++)
				w1[j][k] += rate_w1 * qq[k] * x1[j]; //����������������֮�������Ȩ
		}
		for (j = 0; j < hidenode; j++) //����������ÿ�����ص�Ԫ����������������Ȩֵ
		{
			pp[j] = 0.0;
			for (k = 0; k < outnode; k++) pp[j] += qq[k] * w1[j][k];
			pp[j] = pp[j] * x1[j] * (1 - x1[j]); //�������У����� 
			for (i = 0; i < innode; i++) w[i][j] += rate_w * pp[j] * x[i]; //����������������֮�������Ȩ 
		}
		for (k = 0; k < outnode; k++)
		{
			e += pow(yd[k] - x2[k], 2); //��������� 
		}
		error = e / 2.0;
		for (k = 0; k < outnode; k++)
			b2[k] += rate_b2 * qq[k]; //����������������֮�����ֵ 
		for (j = 0; j < hidenode; j++)
			b1[j] += rate_b1 * pp[j]; //����������������֮�����ֵ
	}
}
//ʶ��
double *BpNet::recognize(double *p)
{
	double x[innode]; //�������� 
	double x1[hidenode];	//�������״ֵ̬
	double x2[outnode]; //������״ֵ̬ 
	double o1[hidenode]; //�����㼤��ֵ 
	double o2[hidenode]; //����㼤��ֵ
	int i, j, k;
	for (i = 0; i < innode; i++) x[i] = p[i];
	for (j = 0; j < hidenode; j++)
	{
		o1[j] = 0.0;
		for (i = 0; i < innode; i++) o1[j] = o1[j] + w[i][j] * x[i]; //���������Ԫ����ֵ
		x1[j] = 1.0 / (1.0 + exp(-o1[j] - b1[j])); //���������Ԫ���
	}
	for (k = 0; k < outnode; k++)
	{
		o2[k] = 0.0;
		for (j = 0; j < hidenode; j++) o2[k] = o2[k] + w1[j][k] * x1[j]; //��������Ԫ����ֵ 
		x2[k] = 1.0 / (1.0 + exp(-o2[k] - b2[k])); //��������Ԫ��� 
	}
	for (k = 0; k < outnode; k++)
	{
		result[k] = x2[k];
	}
	return result;
}
