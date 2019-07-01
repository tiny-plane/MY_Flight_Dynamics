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
#include "section.h"


class surface
{
protected: ///����
	char name;
	enum kind
	{
		fuselage,
		wing,
		h_sta,
		v_sta
	};
	int slices; /// ��������
	int Nchord = 10; ///number of chordwise horseshoe vortices placed on the surface
	double Cspace = 0; ///chordwise vortex spacing parameter(described later)

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

	int component = 1;

	double  translate[3] = { 0,0,0 };
	/*	The TRANSLATE keyword allows convenient relocation of the entire surface without the
	need to change the Xle,Yle,Zle locations  for all the defining sections. 
	A body can be translated without the need to modify the body shape coordinates. 
    dX,dY,dZ =  offset added on to all X,Y,Z values in this surface. 	*/

	double scale[3] = { 1, 1, 1 };///scaling factors applied to all x, y, z coordinates

	
public: ///����	
	int get_kind(int kind_raw);
	virtual bool Init_var(void); ///�����齨�����Լ��ĳ�ʼ������
	virtual bool build(void);

public:///debug*
	virtual double debug(int kind_debug);
};