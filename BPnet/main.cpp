#include "main.h"

//输入样本 
double X[trainsample][innode] = { { 1,0,0,0,0,0,0,0 },{ 0,1,0,0,0,0,0,0 },{ 0,0,1,0,0,0,0,0 },{ 0,0,0,1,0,0,0,0 },{ 0,0,0,0,1,0,0,0 },{ 0,0,0,0,0,1,0,0 },{ 0,0,0,0,0,0,1,0 },{ 0,0,0,0,0,0,0,1 } };
int main2()
{
	srand(time(NULL));
	int i, j, k;
	BpNet bp;
	bp.init();
	int times = 0;
	while (bp.error > 0.0001 && times < 5000)
	{
		bp.e = 0.0; times++; bp.train(X, X);
	}
	double m[innode] = { 0,0,1,0,0,0,0,0 };
	bp.recognize(m);
	for (i = 0; i < innode; ++i) 
		std::cout << m[i];
	std::cout << " is ";
	for (i = 0; i < outnode; i++)
		printf("%d", (int)floor(bp.result[i] + 0.5));
	std::cout << std::endl;
	system("pause");
	return 0;
}
int main()
{
	const int hidnodes = 8; //单层隐藏层的结点数
	const int inNodes = 10;   //输入层结点数
	const int outNodes = 5;  //输出层结点数

	const int trainClass = 5; //5个类别
	const int numPerClass = 30;  //每个类别30个样本点

	int sampleN = trainClass*numPerClass;     //每类训练样本数为30，5个类别，总的样本数为150
	float **trainMat = new float*[sampleN];                         //生成训练样本
	for (int k = 0; k < trainClass; ++k) {
		for (int i = k * numPerClass; i < (k + 1) * numPerClass; ++i) {
			trainMat[i] = new float[inNodes];
			for (int j = 0; j < inNodes; ++j) {
				trainMat[i][j] = rand() % 1000 / 10000.0 + 0.1*(2 * k + 1);

			}
		}
	}

	int **labelMat = new int*[sampleN]; //生成标签矩阵
	for (int k = 0; k < trainClass; ++k) {
		for (int i = k * numPerClass; i < (k + 1) * numPerClass; ++i) {
			labelMat[i] = new int[outNodes];
			for (int j = 0; j <trainClass; ++j) {
				if (j == k)
					labelMat[i][j] = 1;
				else
					labelMat[i][j] = 0;
			}

		}
	}

	Ann_bp ann_classify(sampleN, inNodes, outNodes, hidnodes, 0.12);  //输入层为10个结点，输出层5个结点，单层隐藏层
	ann_classify.train(sampleN, trainMat, labelMat);


	for (int i = 0; i < 30; ++i) {
		ann_classify.predict(trainMat[i + 120], NULL);
		std::cout << std::endl;
	}


	//释放内存
	for (int i = 0; i < sampleN; ++i)
		delete[] trainMat[i];
	delete[] trainMat;

	for (int i = 0; i < sampleN; ++i)
		delete[] labelMat[i];
	delete[] labelMat;

	return 0;
}