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
#include "surface.h"

class wing : public surface
{
protected: ///����
	section* s[100];
	int num; ///�ж��ٸ����棬ÿ�����ע���޸������ֵ
public: ///����
	double cac_wing_aera(void);
	double cac_wing_MAC(void);

	virtual bool build(void);
public:///debug
	virtual double debug(int kind_debug);
};