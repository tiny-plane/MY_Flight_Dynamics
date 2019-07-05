#include <gl/glut.h>
#include <stdio.h>
#include "vari.h"
#include "base.h"
#pragma once
using namespace std;

class Keybord_Fun : public base
{
public:
	Keybord_Fun(int key, int x, int y, vari& v);
	void orientMe(float ang, vari& v);
	void moveMeFlat(float direction, vari& v);
};