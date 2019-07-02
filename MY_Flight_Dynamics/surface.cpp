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
	//连接两个截面
	front.after = &after;
	after.front = &front;
}
void surface::insert_section(section& front, section& newsection, section& after)
{
	//中间插入一个截面
	slices++;
	this->connet_section(front, newsection);
	this->connet_section(newsection, after);
}
void surface::delete_section(section& front, section& deletesection, section& after)
{
	//中间删除一个截面
	slices--;
	this->connet_section(front, after);
	delete &deletesection;
}
void surface::append_section(section& newsection)
{
	//在后部添加一个截面
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
