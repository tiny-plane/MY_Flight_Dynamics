#include "main.h"
//ÊäÈëÑù±¾ 
double X[trainsample][innode] = { { 1,0,0,0,0,0,0,0 },{ 0,1,0,0,0,0,0,0 },{ 0,0,1,0,0,0,0,0 },{ 0,0,0,1,0,0,0,0 },{ 0,0,0,0,1,0,0,0 },{ 0,0,0,0,0,1,0,0 },{ 0,0,0,0,0,0,1,0 },{ 0,0,0,0,0,0,0,1 } };
int main()
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
