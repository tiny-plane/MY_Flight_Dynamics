#include "main_code.h"


bool Draw(void)
{
	section* news;
	news = new section;
	double pos[3] = { 0.0,0.0,0.0};
	news->Set_pos(pos);
	news->Set_ainc(2.0);
	news->Set_chord(2.0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("afiltest.dat"));
	W.init_section(*news);

	section* news2;
	news2 = new section;
	double pos2[3] = { 0.0,2.0,0.0 };
	news2->Set_pos(pos2);
	news2->Set_ainc(2.0);
	news2->Set_chord(1.0);
	news2->Set_afil_type(1);
	news2->Set_afil_afilname(std::string("afiltest.dat"));
	W.append_section(*news2);


	section* news3;
	news3 = new section;
	double pos3[3] = { -3,4,2 };
	news3->Set_pos(pos3);
	news3->Set_ainc(0.0);
	news3->Set_chord(0.5);
	news3->Set_afil_type(1);
	news3->Set_afil_afilname(std::string("afiltest2.dat"));
	W.append_section(*news3);

	W.set_angle(2);

	section* news4;
	news4 = new section;
	double pos4[3] = {-5,0,0 };
	news4->Set_pos(pos4);
	news4->Set_ainc(0.0);
	news4->Set_chord(0.5);
	news4->Set_afil_type(1);
	news4->Set_afil_afilname(std::string("afiltest2.dat"));
	st.init_section(*news4);

	section* news5;
	news5 = new section;
	double pos5[3] = { -5,1,0.5 };
	news5->Set_pos(pos5);
	news5->Set_ainc(0.0);
	news5->Set_chord(0.5);
	news5->Set_afil_type(1);
	news5->Set_afil_afilname(std::string("afiltest2.dat"));
	st.append_section(*news5);
	
	st.set_name(std::string("vsta"));
	st.set_index(4);
	st.set_angle(0);
	return false;
}
int main(int args, char argv[])
{
	Draw();
	W.fresh_data();	
	W.updata2var(v);
	v.fresh_var();
	W.set_name(string("main wing"));
	file_oper F;
	string str = "D:\\MY_Flight_Dynamics\\MY_Flight_Dynamics\\data";	
	F.build_avl(str,v,W,st);
	F.build_run(str,v);
	system("pause");
	return 0;
}
