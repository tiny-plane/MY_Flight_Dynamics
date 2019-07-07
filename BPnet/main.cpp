#include "main.h"

//�������� 
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
	const int hidnodes = 8; //�������ز�Ľ����
	const int inNodes = 10;   //���������
	const int outNodes = 5;  //���������

	const int trainClass = 5; //5�����
	const int numPerClass = 30;  //ÿ�����30��������

	int sampleN = trainClass*numPerClass;     //ÿ��ѵ��������Ϊ30��5������ܵ�������Ϊ150
	float **trainMat = new float*[sampleN];                         //����ѵ������
	for (int k = 0; k < trainClass; ++k) {
		for (int i = k * numPerClass; i < (k + 1) * numPerClass; ++i) {
			trainMat[i] = new float[inNodes];
			for (int j = 0; j < inNodes; ++j) {
				trainMat[i][j] = rand() % 1000 / 10000.0 + 0.1*(2 * k + 1);

			}
		}
	}

	int **labelMat = new int*[sampleN]; //���ɱ�ǩ����
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

	Ann_bp ann_classify(sampleN, inNodes, outNodes, hidnodes, 0.12);  //�����Ϊ10����㣬�����5����㣬�������ز�
	ann_classify.train(sampleN, trainMat, labelMat);


	for (int i = 0; i < 30; ++i) {
		ann_classify.predict(trainMat[i + 120], NULL);
		std::cout << std::endl;
	}


	//�ͷ��ڴ�
	for (int i = 0; i < sampleN; ++i)
		delete[] trainMat[i];
	delete[] trainMat;

	for (int i = 0; i < sampleN; ++i)
		delete[] labelMat[i];
	delete[] labelMat;

	return 0;
}