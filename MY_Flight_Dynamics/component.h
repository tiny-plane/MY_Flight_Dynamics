#pragma once
/*
飞机外形设计和优化程序
创建时间2019年6月29日
创建人：邸伟承，王家琛
///
修改日志：
2019年6月26日 创建文件



///
问题记录：




///
联系方式：
邸伟承
手机号：15388646168
邮箱：823036067@qq.com
*/

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "section.h"


class component
{
public: ///属性
	char name;
	enum kind 
	{
		fuselage,
		wing,
		wing_tip,
		h_sta,
		v_sta
	};
	int slices; /// 截面数量
	int stack;
	int version;


public: ///方法	
	int get_kind(int kind_raw);
	virtual bool Init_var(void); ///各自组建重载自己的初始化方法
	virtual bool build(void);

public:///debug*
	virtual double debug(int kind_debug);
};