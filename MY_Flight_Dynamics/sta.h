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
#include <string>
class sta : public surface
{
public: ///����

	int num; ///�ж��ٸ����棬ÿ�����ע���޸������ֵ

public: ///����
	double cac_wing_aera(void);
	bool fresh_data(void);
	double cac_wing_MAC(void);
	double cac_wing_span_length(void);
	virtual bool build(void);
public:///debug
	virtual double debug(int kind_debug);
};