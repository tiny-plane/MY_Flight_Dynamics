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
#include "component.h"

class wing : public component
{
public: ///����
	double chord;

public: ///����
	double cac_wing_aera(void);
	double cac_wing_MAC(void);

};