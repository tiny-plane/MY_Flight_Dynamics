#include "BpNet.h"

using namespace std;


BpNet::BpNet() {
	error = 1.0;
	e = 0.0;
	rate_w = 0.1; //权值学习率（输入层--隐含层)
	rate_w1 = 0.1; //权值学习率 (隐含层--输出层)
	rate_b1 = 0.1; //隐含层阀值学习率
	rate_b2 = 0.1; //输出层阀值学习率 
}
BpNet::~BpNet()
{
}
//产生[low, high)之间的随机数
double randval(double low, double high)
{
	double val;
	val = ((double)(rand() % RAND_MAX) / (double)RAND_MAX) * (high - low) + low;
	return(val);
}
void winit(double w[], int n) //权值初始化 
{
	for (int i = 0; i < n; i++)
		w[i] = randval(-0.01, 0.01);
}
//初始化 
void BpNet::init()
{
	winit((double*)w, innode * hidenode);
	winit((double*)w1, hidenode * outnode);
	winit(b1, hidenode);
	winit(b2, outnode);
}
//训练
void BpNet::train(double p[trainsample][innode], double t[trainsample][outnode])
{
	double pp[hidenode]; 	//隐含结点的校正误差 
	double qq[outnode]; //希望输出值与实际输出值的偏差 
	double yd[outnode]; //希望输出值 
	double x[innode]; //输入向量
	double x1[hidenode]; //隐含结点状态值
	double x2[outnode]; //输出结点状态值 
	double o1[hidenode]; //隐含层激活值
	double o2[hidenode]; //输出层激活值

	for (int isamp = 0; isamp < trainsample; isamp++) //循环训练一次样品 
	{
		int i, j, k;
		for (i = 0; i < innode; i++)
			x[i] = p[isamp][i]; //输入的样本
		for (i = 0; i < outnode; i++)
			yd[i] = t[isamp][i]; //希望输出的样本
//正向传播 
							 //构造每个样品的输入和输出标准
		for (j = 0; j < hidenode; j++)
		{
			o1[j] = 0.0;
			for (i = 0; i < innode; i++)
				o1[j] += w[i][j] * x[i]; //隐含层各单元输入激活值
			x1[j] = 1.0 / (1.0 + exp(-o1[j] - b1[j])); //隐含层各单元的输出 
		}
		for (k = 0; k < outnode; k++)
		{
			o2[k] = 0.0;
			for (int j = 0; j < hidenode; j++)
				o2[k] += w1[j][k] * x1[j]; //输出层各单元输入激活值 
			x2[k] = 1.0 / (1.0 + exp(-o2[k] - b2[k])); //输出层各单元输出 
		}

		//误差反向传播 
		for (k = 0; k < outnode; k++) //对于网络中每个输出单元，计算误差项，并更新权值
		{
			qq[k] = (yd[k] - x2[k]) * x2[k] * (1 - x2[k]); //希望输出与实际输出的偏差 
			for (j = 0; j < hidenode; j++)
				w1[j][k] += rate_w1 * qq[k] * x1[j]; //更新隐含层和输出层之间的连接权
		}
		for (j = 0; j < hidenode; j++) //对于网络中每个隐藏单元，计算误差项，并更新权值
		{
			pp[j] = 0.0;
			for (k = 0; k < outnode; k++) pp[j] += qq[k] * w1[j][k];
			pp[j] = pp[j] * x1[j] * (1 - x1[j]); //隐含层的校正误差 
			for (i = 0; i < innode; i++) w[i][j] += rate_w * pp[j] * x[i]; //更新输入层和隐含层之间的连接权 
		}
		for (k = 0; k < outnode; k++)
		{
			e += pow(yd[k] - x2[k], 2); //计算均方差 
		}
		error = e / 2.0;
		for (k = 0; k < outnode; k++)
			b2[k] += rate_b2 * qq[k]; //更新隐含层和输出层之间的阈值 
		for (j = 0; j < hidenode; j++)
			b1[j] += rate_b1 * pp[j]; //更新输入层和隐含层之间的阈值
	}
}
//识别
double *BpNet::recognize(double *p)
{
	double x[innode]; //输入向量 
	double x1[hidenode];	//隐含结点状态值
	double x2[outnode]; //输出结点状态值 
	double o1[hidenode]; //隐含层激活值 
	double o2[hidenode]; //输出层激活值
	int i, j, k;
	for (i = 0; i < innode; i++) x[i] = p[i];
	for (j = 0; j < hidenode; j++)
	{
		o1[j] = 0.0;
		for (i = 0; i < innode; i++) o1[j] = o1[j] + w[i][j] * x[i]; //隐含层各单元激活值
		x1[j] = 1.0 / (1.0 + exp(-o1[j] - b1[j])); //隐含层各单元输出
	}
	for (k = 0; k < outnode; k++)
	{
		o2[k] = 0.0;
		for (j = 0; j < hidenode; j++) o2[k] = o2[k] + w1[j][k] * x1[j]; //输出层各单元激活值 
		x2[k] = 1.0 / (1.0 + exp(-o2[k] - b2[k])); //输出层各单元输出 
	}
	for (k = 0; k < outnode; k++)
	{
		result[k] = x2[k];
	}
	return result;
}
