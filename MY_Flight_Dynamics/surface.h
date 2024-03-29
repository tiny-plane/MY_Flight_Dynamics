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
#include <string>
#include "var.h"

class surface
{
protected: ///属性
	std::string name;

	enum kind
	{
		fuselage,
		wing,
		sta
	};
	int slices=0; /// 截面数量
	int Nchord = 10; ///number of chordwise horseshoe vortices placed on the surface
	double Cspace = 1.0; ///chordwise vortex spacing parameter(described later)

	bool nowake = false;
	/*The NOWAKE keyword specifies that this surface is to NOT shed a wake,
	so that its strips will not have their Kutta conditions imposed.
	Such a surface will have a near-zero net lift, but it will still
	generate a nonzero moment. */

	bool noalbe = false;
	/*The NOALBE keyword specifies that this surface is unaffected by freestream
	direction changes specified by the alpha,beta angles and p,q,r rotation rates.
	This surface then reacts to only to the perturbation velocities of all the horseshoe
	vortices and  sources and doublets in the flow.
	This allows the SURFACE/NOALBE object to model fixed surfaces such as a ground plane,
	wind tunnel walls, or a nearby other aircraft  which is at a fixed flight condition. */

	bool noload = false;
	/*The NOLOAD keyword specifies that the force and moment on this surface is to NOT
	be included in the overall forces and moments of the configuration. This is typically
	used together with NOALBE, since the force on a ground plane or wind tunnel walls
	certainly is not to be considered as part of the aircraft force of interest. */


	bool yduplicate = false;
	int index = 3;
	int component = 1;

	double  translate[3] = { 0,0,0 };
	/*	The TRANSLATE keyword allows convenient relocation of the entire surface without the
	need to change the Xle,Yle,Zle locations  for all the defining sections. 
	A body can be translated without the need to modify the body shape coordinates. 
    dX,dY,dZ =  offset added on to all X,Y,Z values in this surface. 	*/

	double scale[3] = { 1, 1, 1 };///scaling factors applied to all x, y, z coordinates
	double angle = 0;
	double aera = 0;
	double mac = 0;
	double spanlen = 1;
public:
	section* orisection;
	section* nowsection;

public: ///方法	
	~surface(void);
	int get_kind(int kind_raw);
	virtual bool Init_var(void); ///各自组建重载自己的初始化方法
	virtual bool build(void);
	template <class T> T dec2rad(T in);
	template <class T> T rad2dec(T in);
	void connet_section(section& front, section& after);
	void insert_section(section& front, section& newsection, section& after);
	void delete_section(section& front, section& deletesection, section& after);
	void append_section(section& newsection);
	void init_section(section& init);
	section* find_section_with_num(int num);
	void move_nowsection_point(section& newnowsection);
	virtual bool fresh_data(void);
	double get_aera(void);
	double get_Cspace(void);
	int get_slices(void);
	int get_Nchord(void);
	double get_spanlen(void);
	void set_spanlen(double spanlen);
	void set_aera(double aera);
	int get_index(void);
	double get_angle(void);
	std::string get_name(void);
	double get_mac(void);
	void set_mac(double mac);
	void set_index(int index);
	void set_angle(double angle);
	void set_name(std::string name);
	void set_Nchord(int Nchord);
	void updata_aera(var& v);
	void updata_mac(var& v);
	void updata_spanlen(var& v);
	void updata2var(var& v);
public:///debug*
	virtual double debug(int kind_debug);
};

template <class T>
inline T surface::dec2rad(T in)
{
	return in / 180 * 3.141592653;
}
template <class T>
inline T surface::rad2dec(T in)
{
	return in * 180 / 3.141592653;
}
