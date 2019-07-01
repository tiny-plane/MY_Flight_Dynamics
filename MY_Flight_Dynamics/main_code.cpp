#include "main_code.h"


double data[2][5] = { { 1,0,0,0,2 },{ 1,0,2,0.1,-1 } };

template<class T>
int length(T& arr)
{
	return sizeof(arr) / sizeof(arr[0]);
}
bool Draw(void)
{
	std::cout << length(data) << std::endl;

	//for(int i = sizeof(data))
	return false;
}
int main(int args,char argv[])
{
	Draw();
	system("pause");
	return 0;
}
