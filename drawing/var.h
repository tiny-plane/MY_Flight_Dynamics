#pragma once
#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>
#include "base.h"

using namespace std;

class var : public base
{
public:
	float red = 0.0f, blue = 0.0f, green = 0.0f;
	float angle_y = 0.0f; //��y�����ת�ǣ������������������ת�����
	float angle_x = 0.0f;
	float x = 0.0f, y = 1.75f, z = 5.0f;  //�����λ��
	float lx = 0.0f, ly = 0.0f, lz = -1.0f; //һ����������ָʾ���ǵ����߷���
	float dep = 100.0f;
	float dep2 = 10;
	int specialKey = 0;
	int width = 200, height = 200;
	float deltaAngle = 0.0f;
	bool color_changed = false;
	float ratio = 1.0f;
	float zall = -10.0f;
	float angr = 0.0f;
	float dis = 0.0f;
	float dis_tree = -500.0f;
	float last_x = 0.0f;
	float last_y = 0.0f;
	float dif_x = 100, dif_y = 100;
	float rotate_speed = 0.0f;
	int mode = 1;
	float speed = 1.0f;
	bool auto_changecolor = false;
	bool enable_DEPTH = false;
	bool enable_SMOOTH = true;
	float dis_road = 0.0f;
	var(void);
	void ChangeColor(float red, float green, float blue);
};
