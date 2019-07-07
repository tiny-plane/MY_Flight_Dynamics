#pragma once
#include <iostream> 
#include <cmath>
#include "stdio.h"
#include "stdlib.h"
#include "time.h" 
#define  innode 8  //输入结点数
#define  hidenode 4   //隐含结点数
#define  outnode 8      //输出结点数
#define  trainsample 8  //BP训练样本数


class BpNet
{
public:
	void train(double p[trainsample][innode], double t[trainsample][outnode]);//Bp训练 
	double p[trainsample][innode]; //输入的样本 
	double t[trainsample][outnode]; //样本要输出的 
	double *recognize(double *p); //Bp识别 
	BpNet();
	virtual ~BpNet();
public:
	void init();
	double w[innode][hidenode]; 	//隐含结点权值 
	double w1[hidenode][outnode]; 	//输出结点权值
	double b1[hidenode]; //隐含结点阀值 
	double b2[outnode]; //输出结点阀值 
	double rate_w; //权值学习率（输入层-隐含层)
	double rate_w1; //权值学习率 (隐含层-输出层) 
	double rate_b1; //隐含层阀值学习率 
	double rate_b2; //输出层阀值学习率
	double e; //误差计算
	double error; //允许的最大误差 
	double result[outnode]; // Bp输出
};
