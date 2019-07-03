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
#include <string>
class var
{
protected:///属性
	double mass = 3.8; /// 总质量
	double add_mass[100]; /// 附加集中质量
	double surf_mass[100]; /// 均布质量
	std::string name = "test";
	double I[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

	double Xref = 0.0, Yref = 0.0, Zref = 0.0;

	double iYsym, iZsym, Zsym;

	double mach=0;

	double Sref = 0.0, Cref = 0.0, Bref = 0.0;

	double local_speedofsound = 340;
	double CDo = 0.02;
	double velocity = 10;
	double density = 1.25;
	double gravity = 9.8;
	double alpha = 0;
	double beta = 0;

public: ///方法
	bool Init_var(void);
	void fresh_var(void);
	double get_alpha(void);
	double get_beta(void);
	double get_mach(void);
	double get_velocity(void);
	double get_Xref(void);
	double get_Yref(void);
	double get_Zref(void);
	double get_Sref(void);
	double get_Cref(void);
	double get_Bref(void);
	double get_mass(void);
	double get_density(void);
	double get_gravity(void);
	double get_CDo(void);
	double get_Ixx(void);
	double get_Iyy(void);
	double get_Izz(void);
	double get_Ixy(void);
	double get_Iyz(void);
	double get_Izx(void);

	void set_alpha(double alpha);
	void set_beta(double beta);
	void set_mach(double in);
	void set_velocity(double in);
	void set_Xref(double in);
	void set_Yref(double in);
	void set_Zref(double in);
	void set_Sref(double in);
	void set_Cref(double in);
	void set_Bref(double in);
	void set_mass(double in);
	void set_density(double in);
	void set_gravity(double in);
	void set_CDo(double in);
	void set_name(std::string name);
	void set_I(double Ixx,double Iyy,double Izz,double Ixy,double Iyz,double Izx);
	std::string get_name(void);
};