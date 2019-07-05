#include "vari.h"
#include <iostream>
using namespace std;

vari::vari(void)
{
	//cout << "Object is being created" << endl;

}
void vari::ChangeColor(float red, float green, float blue)
{
	this->color_changed = true;
	this->red = red;
	this->green = green;
	this->blue = blue;
}
