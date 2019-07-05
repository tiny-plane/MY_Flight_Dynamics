#include "sta.h"

double sta::debug(int kind_debug)
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
bool sta::build(void)
{
	return true;
}
double sta::cac_wing_aera(void)
{
	//slices������1������ʾ����������׼ȷ�Ľ���������������������ʱ��ע�⡣

	//����������������Ͳ����Լ���
	//std::cout << "����������"<< this->slices << std::endl;
	if (this->slices <= 1)
	{
		return 0;
	}
	double aera = 0;
	//��������治����ɾ����Ĭ�ϵ�һ�����������0�Ž���
	section* next = this->orisection;
	double l1 = 0;
	double l2 = 0;
	double h = 0;
	for (int i = 1; i < this->slices; i++)
	{
		//����Ťת�ǺͰ�װ�ǵ�Ӱ�졣
		l1 = next->Get_chord() * cos(this->dec2rad(next->Get_ainc() + this->angle));
		l2 = next->after->Get_chord() * cos(this->dec2rad(next->after->Get_ainc() + this->angle));
		h = abs(next->Get_pos()[1] - next->after->Get_pos()[1]);
		aera += (l1 + l2)* h / 2.0;
		//std::cout <<"l1 = " <<  l1 << "  l2 =  "<< l2 << "  h =  " << h << "  aera = "<< aera << std::endl;
		next = next->after;
	}
	return 2.0 * aera;
}
bool sta::fresh_data(void)
{
	this->set_aera(this->cac_wing_aera());
	this->set_mac(this->cac_wing_MAC());
	this->set_spanlen(this->cac_wing_span_length());
	return true;
}

double sta::cac_wing_MAC(void)
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
		//����Ťת�ǺͰ�װ�ǵ�Ӱ�졣
		l1 = next->Get_chord() * cos(this->dec2rad(next->Get_ainc() + this->angle));
		l2 = next->after->Get_chord() * cos(this->dec2rad(next->after->Get_ainc() + this->angle));
		h = abs(next->Get_pos()[1] - next->after->Get_pos()[1]);
		integration += (h*(l1*l1 + l1*l2 + l2*l2)) / 3;
		next = next->after;
	}

	return 2.0 * integration / this->get_aera();
}

double sta::cac_wing_span_length(void)
{
	return 2.0 * this->nowsection->Get_pos()[1];
}
