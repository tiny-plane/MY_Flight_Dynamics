#include "surface.h"
surface::~surface(void)
{
	//this->nowsection = this->orisection;
}
int surface::get_kind(int kind_raw)
{
	return 0;
}
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

double surface::get_Cspace(void)
{
	return this->Cspace;
}

int surface::get_slices(void)
{
	return this->slices;
}

int surface::get_Nchord(void)
{
	return this->Nchord;
}

double surface::get_spanlen(void)
{
	return this->spanlen;
}

void surface::set_spanlen(double spanlen)
{
	this->spanlen = spanlen;
}

void surface::set_aera(double aera)
{
	this->aera = aera;
}

int surface::get_index(void)
{
	return this->index;
}

double surface::get_angle(void)
{
	return this->angle;
}

std::string surface::get_name(void)
{
	return this->name;
}

double surface::get_mac(void)
{
	return this->mac;
}

void surface::set_mac(double mac)
{
	this->mac = mac;
}

void surface::set_index(int index)
{
	this->index = index;
}

void surface::set_angle(double angle)
{
	this->angle = angle;
}

void surface::set_name(std::string name)
{
	this->name = name;
}

void surface::set_Nchord(int Nchord)
{
	this->Nchord = Nchord;
}

void surface::updata_aera(var & v)
{
	v.set_Sref(this->aera);
}

void surface::updata_mac(var & v)
{
	v.set_Cref(this->mac);
}

void surface::updata_spanlen(var & v)
{
	v.set_Bref(this->spanlen);
}

void surface::updata2var(var & v)
{
	this->updata_aera(v);
	this->updata_mac(v);
	this->updata_spanlen(v);
}
