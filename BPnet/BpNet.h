#pragma once
#include <iostream> 
#include <cmath>
#include "stdio.h"
#include "stdlib.h"
#include "time.h" 
#define  innode 8  //��������
#define  hidenode 4   //���������
#define  outnode 8      //��������
#define  trainsample 8  //BPѵ��������


class BpNet
{
public:
	void train(double p[trainsample][innode], double t[trainsample][outnode]);//Bpѵ�� 
	double p[trainsample][innode]; //��������� 
	double t[trainsample][outnode]; //����Ҫ����� 
	double *recognize(double *p); //Bpʶ�� 
	BpNet();
	virtual ~BpNet();
public:
	void init();
	double w[innode][hidenode]; 	//�������Ȩֵ 
	double w1[hidenode][outnode]; 	//������Ȩֵ
	double b1[hidenode]; //������㷧ֵ 
	double b2[outnode]; //�����㷧ֵ 
	double rate_w; //Ȩֵѧϰ�ʣ������-������)
	double rate_w1; //Ȩֵѧϰ�� (������-�����) 
	double rate_b1; //�����㷧ֵѧϰ�� 
	double rate_b2; //����㷧ֵѧϰ��
	double e; //������
	double error; //����������� 
	double result[outnode]; // Bp���
};
