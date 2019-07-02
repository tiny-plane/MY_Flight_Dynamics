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
#include "surface.h"

class wing : public surface
{
public: ///属性

	int num; ///有多少个截面，每次添加注意修改这个的值
	double angle;
public: ///方法
	double cac_wing_aera(void);
	double cac_wing_MAC(void);

	virtual bool build(void);
public:///debug
	virtual double debug(int kind_debug);
};