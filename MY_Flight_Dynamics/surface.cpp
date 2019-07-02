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

section * surface::find_section_with_num(int num)
{
	if (num >= this->slices)
	{
		return nullptr;
	}
	section* temp;
	temp = this->orisection;
	for (int i = 1; i < num; i++)
	{
		temp = temp->after;
	}
	return temp;
}

void surface::move_nowsection_point(section & newnowsection)
{
	this->nowsection = &newnowsection;
}

bool surface::fresh_data(void)
{
	return false;
}

double surface::get_aera(void)
{
	return this->aera;
}

void surface::set_aera(double aera)
{
	this->aera = aera;
}

double surface::get_mac(void)
{
	return this->mac;
}

void surface::set_mac(double mac)
{
	this->mac = mac;
}
