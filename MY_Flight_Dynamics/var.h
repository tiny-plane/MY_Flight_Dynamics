#pragma once
/*
�ɻ�������ƺ��Ż�����
����ʱ��2019��6��29��
�����ˣ�ۡΰ�У������
///
�޸���־��
2019��6��26�� �����ļ�



///
�����¼��




///
��ϵ��ʽ��
ۡΰ��
�ֻ��ţ�15388646168
���䣺823036067@qq.com
*/

#include <iostream>
#include <math.h>

class var
{
protected:///����
	double mass; /// ������
	double add_mass[100]; /// ���Ӽ�������
	double surf_mass[100]; /// ��������

	double I[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

	double Xref, Yref, Zref;

	double iYsym, iZsym, Zsym;

	double mach;

	double Sref, Cref, Bref;


	double CDo = 0.02;
	double velocity = 10;
	double density = 1.25;
	double gravity = 9.8;


public: ///����
	bool Init_var();
};