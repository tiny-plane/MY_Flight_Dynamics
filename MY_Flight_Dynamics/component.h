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

#include <stdio.h>
#include <iostream>
#include <math.h>

class component
{
public: ///����
	char name;
	enum kind 
	{
		fuselage,
		wing,
		wing_tip,
		h_sta,
		v_sta
	};
	int slices; /// ��������
	int stack;
	int version;


public: ///����	
	int get_kind(int kind_raw);
	virtual bool Init_var(); ///�����齨�����Լ��ĳ�ʼ������
};