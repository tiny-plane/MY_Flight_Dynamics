#include "wing.h"

double wing::debug(int kind_debug)
{
	switch (kind_debug)
	{
	case 1:
		this->build();
		//return cac_wing_aera();
		return 0;
		break;
	default:
		break;
	}
	return 0;
}
bool wing::build(void)
{
	return true;
}
double wing::cac_wing_aera(void)
{
	//slices至少有1个，显示的数量就是准确的截面数量，但这里索引的时候注意。

	//如果截面少于两个就不可以计算
	//std::cout << "截面数量："<< this->slices << std::endl;
	if (this->slices <= 1)
	{
		return 0;
	}
	double aera = 0;
	//另外根截面不可以删除，默认第一个截面必须是0号截面
	section* next = this->orisection;
	double l1 = 0;
	double l2 = 0;
	double h = 0;
	for (int i = 1; i < this->slices; i++)
	{
		//考虑扭转角和安装角的影响。
		l1 = next->Get_chord() * cos(this->dec2rad(next->Get_ainc() + this->angle));
		l2 = next->after->Get_chord() * cos(this->dec2rad(next->after->Get_ainc() + this->angle));
		h = abs(next->Get_pos()[1] - next->after->Get_pos()[1]);
		aera += (l1 + l2)* h / 2.0;
		//std::cout <<"l1 = " <<  l1 << "  l2 =  "<< l2 << "  h =  " << h << "  aera = "<< aera << std::endl;
		next = next->after;
	}
		return 2.0 * aera;
}
bool wing::fresh_data(void)
{
	this->set_aera(this->cac_wing_aera());
	this->set_mac(this->cac_wing_MAC());
	this->set_spanlen(this->cac_wing_span_length());
	return true;
}

double wing::cac_wing_MAC(void)
{
	if (this->slices < 2)
	{
		return 0;
	}
	section* next = this->orisection;
	double l1 = 0;
	double l2 = 0;
	double h = 0;
	double integration = 0;
	double hlast = 0;
	for (int i = 1; i < this->slices; i++)
	{
		//考虑扭转角和安装角的影响。
		l1 = next->Get_chord() * cos(this->dec2rad(next->Get_ainc() + this->angle));
		l2 = next->after->Get_chord() * cos(this->dec2rad(next->after->Get_ainc() + this->angle));
		h = abs(next->Get_pos()[1] - next->after->Get_pos()[1]);
		integration += (h*(l1*l1 + l1*l2 + l2*l2)) / 3;
		next = next->after;
	}

	return 2.0 * integration / this->get_aera();
}

double wing::cac_wing_span_length(void)
{
	return 2.0 * this->nowsection->Get_pos()[1];
}

