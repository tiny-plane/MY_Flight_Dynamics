#include "main_code.h"
#include <iostream>

bool Draw(void)
{
	section* news;
	news = new section;
	double pos[3] = { 0.0,0.0,0.0};
	news->Set_pos(pos);
	news->Set_ainc(2.0);
	news->Set_chord(2.0);

	W.init_section(*news);

	section* news2;
	news2 = new section;
	double pos2[3] = { 0.0,2.0,0.0 };
	news2->Set_pos(pos2);
	news2->Set_ainc(2.0);
	news2->Set_chord(1.0);

	W.append_section(*news2);

	section* news3;
	news3 = new section;
	double pos3[3] = {-3,4,2 };
	news3->Set_pos(pos3);
	news3->Set_ainc(0.0);
	news3->Set_chord(0.5);
	W.append_section(*news3);

	W.angle = 2;
	
	return false;
}
int main(int args, char argv[])
{
	Draw();
	W.fresh_data();	
	std::cout << W.get_aera() << std::endl;
	std::cout << W.get_mac() << std::endl;
	system("pause");
	return 0;
}
