#include "surface.h"
bool surface::Init_var(void)
{
	return false;
}

bool surface::build(void)
{
	return false;
}

double surface::debug(int kind_debug)
{
	return 0.0;
}

void surface::connet_section(section& front, section& after)
{
	//������������
	front.after = &after;
	after.front = &front;
}
void surface::insert_section(section& front, section& newsection, section& after)
{
	//�м����һ������
	slices++;
	this->connet_section(front, newsection);
	this->connet_section(newsection, after);
}
void surface::delete_section(section& front, section& deletesection, section& after)
{
	//�м�ɾ��һ������
	slices--;
	this->connet_section(front, after);
	delete &deletesection;
}
void surface::append_section(section& newsection)
{
	//�ں����һ������
	slices++;
	this->connet_section(*(this->nowsection), newsection);
	this->nowsection = &newsection;
}

void surface::init_section(section& init)
{
	this->orisection = &init;
	this->slices = 1;
	this->nowsection = &init;
}
