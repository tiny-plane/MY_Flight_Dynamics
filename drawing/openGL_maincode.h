#pragma once
#include <windows.h>
#include <gl/glew.h>  
#include <gl/freeglut.h>
#include <stdio.h>
#include "Keybord_Fun.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Mouse_Fun.h"
#include "vari.h"
#include <iostream>
#include <math.h>
#include "D:\MY_Flight_Dynamics\MY_Flight_Dynamics\MY_Flight_Dynamics\var.h"
#include "D:\MY_Flight_Dynamics\MY_Flight_Dynamics\MY_Flight_Dynamics\surface.h"
#include "D:\MY_Flight_Dynamics\MY_Flight_Dynamics\MY_Flight_Dynamics\wing.h"
#include "D:\MY_Flight_Dynamics\MY_Flight_Dynamics\MY_Flight_Dynamics\sta.h"
#include <string>
#include <fstream>
#include <windows.h>
#include <thread>
#pragma warning(disable:4996)
#define BMP_Header_Length 54  //ͼ���������ڴ���е�ƫ����


template<class T>
int length(T& arr);
	wing w;
	sta st;
bool Draw(wing& W, sta& st);
bool Write2avl(void);
bool Readfromavl;
GLfloat ctrlpoints[4][4][3] = {
	{ { -5, -5, 1 },
	{ -5, -5, 2 },
	{ 5, -15, -3 },
	{ 5, -5, 4} },

	{ { -15, -5, 1 },
	{ -5, 5, 2 },
	{ 5, 15, 3 },
	{ 5, -5, -4 } },

	{ { -1, 5, 2 },
	{ -15, 5, 1 },
	{ 5, 15, 3 },
	{ 5, -1, 1 } },

	{ { -5, 5, -2 },
	{ -15, 5, -2 },
	{ 5, 15, 1 },
	{ 15, 1, -1 } } };
GLfloat knots[8] = { 0.0, 0.0, 0.0, 0.0,1.0, 1.0, 1.0, 1.0 }; // NURBS����Ŀ�������      
GLfloat ambient[] = { 0.4f, 0.6f, 0.2f, 1.0f };
GLfloat position[] = { 10.0f,5.0f,3.0f, 1.0f };
GLfloat mat_diffuse[] = { 0.2f, 0.4f, 0.8f, 1.0f };
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat mat_shininess[] = { 80.0 };
GLuint texGround;
GLuint texTree1;
GLuint texWood;
GLUnurbsObj *theNurb;
float angle = 1.0f;
vari v = vari();
Mouse_Fun M = Mouse_Fun();
double x11 = 0.0, y11 = 100.0, z11 = 300.0;
double x22 = 0.0, y22 = 0.0, z22 = -10.0;
int width = 0, height = 0;
void processNormalKeys(unsigned char key, int x, int y);
void spinDisplay(void);
void processSpecialKeys(int key, int x, int y);
void processMouse(int button, int state, int x, int y);
void processMouseActiveMotion(int x, int y);
void processMousePassiveMotion(int x, int y);
void processMouseEntry(int state);
void ChangeSize(int w, int h);
void Circle();
void centreline(float length, float xo, float yo, float zo, bool xd, bool yd, bool zd);
void cyLinder(float x0, float y0, float z0, float x1, float y1, float z1, double radius,GLuint tex, GLint slices, GLint stack);
void cyLinder(float x0, float y0, float z0, float x1, float y1, float z1, double radius);
void renderScene(wing& w,sta& st);
void renderScene_ori(void);
void Display(void);
void idleDisplay(void);
void main(int argc, char * argv[]);
void processMenuEvents_drawkind(int option);
void processMenuEvents_color(int option);
void processMenuEvents_rotate(int option);
void processMenuEvents_void(int option);
void processMenuEvents_speed(int option);
void processMenuEvents_set(int option);
GLuint load_texture(const char* file_name);
int power_of_two(int n);
void Init(void);
