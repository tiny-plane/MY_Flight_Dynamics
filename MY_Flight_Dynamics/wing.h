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
#include "component.h"

class wing : public component
{
public: ///属性
	double chord;

public: ///方法
	double cac_wing_aera(void);
	double cac_wing_MAC(void);

};