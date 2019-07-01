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

#include <iostream>
#include <math.h>

class var
{
protected:///属性
	double mass; /// 总质量
	double add_mass[100]; /// 附加集中质量
	double surf_mass[100]; /// 均布质量

	double I[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

	double Xref, Yref, Zref;

	double iYsym, iZsym, Zsym;

	double mach;

	double Sref, Cref, Bref;


	double CDo = 0.02;
	double velocity = 10;
	double density = 1.25;
	double gravity = 9.8;


public: ///方法
	bool Init_var();
};