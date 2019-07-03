#include "main_code.h"


bool Draw(void)
{
	double pos[3] = { -0.14 ,0.0 , 0.0 };

	W.set_index(3);
	W.set_angle(3);
	W.set_name(string("main wing"));
	W.set_Nchord(11);
	//1
	section* news;
	news = new section;
	pos[0] = -0.14;
	pos[1] = 0.0;
	pos[2] = 0.0;
	news->Set_pos(pos);
	news->Set_chord(0.55);
	news->Set_ainc(2.5);
	news->Set_Nspan(5);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("JS.dat"));
	W.init_section(*news);
	//2
	news = new section;
	pos[0] = -0.065;
	pos[1] = 0.04;
	pos[2] = 0.0;
	news->Set_pos(pos);
	news->Set_chord(0.4);
	news->Set_ainc(2.5);
	news->Set_Nspan(3);
	news->Set_Sspace(0);
	news->Set_afil_type(0);
	news->Set_afil_afilname(std::string("0030"));
	W.append_section(*news);
	//3
	news = new section;
	pos[0] = 0.0;
	pos[1] = 0.0648;
	pos[2] = 0.0;
	news->Set_pos(pos);
	news->Set_chord(0.30);
	news->Set_ainc(2.5);
	news->Set_Nspan(25);
	news->Set_Sspace(1);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NF.dat"));
	W.append_section(*news);
	//4
	news = new section;
	pos[0] = 0.1083;
	pos[1] = 1.5916;
	pos[2] = 0.1550;
	news->Set_pos(pos);
	news->Set_chord(0.3);
	news->Set_ainc(-0.5);
	news->Set_Nspan(8);
	news->Set_Sspace(1);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NF.dat"));
	W.append_section(*news);

	//5
	news = new section;
	pos[0] = 0.2513;
	pos[1] = 1.7448;
	pos[2] = 0.0188;
	news->Set_pos(pos);
	news->Set_chord(0.1);
	news->Set_ainc(0.0);
	news->Set_Nspan(8);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NF.dat"));
	W.append_section(*news);


	st.set_name(std::string("vsta"));
	st.set_index(4);
	st.set_angle(0);
	st.set_Nchord(11);

	//1
	news = new section;
	pos[0] = 0.45;
	pos[1] = 0.0;
	pos[2] = 0.0;
	news->Set_pos(pos);
	news->Set_chord(0.22);
	news->Set_ainc(0.0);
	news->Set_Nspan(10);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NACA0012.dat"));
	st.init_section(*news);
	//2
	news = new section;
	pos[0] = 0.65;
	pos[1] = 0.23;
	pos[2] = -0.0002;
	news->Set_pos(pos);
	news->Set_chord(0.08);
	news->Set_ainc(-0.5);
	news->Set_Nspan(10);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NACA0012.dat"));
	st.append_section(*news);

	return false;
}

void draw_round(double houlue, double yishaohoulue)
{
	double pos[3] = { -0.14 ,0.0 , 0.0 };

	W.set_index(3);
	W.set_angle(3);
	W.set_name(string("main wing"));
	W.set_Nchord(11);
	//1
	section* news;
	news = new section;
	pos[0] = -0.14;
	pos[1] = 0.0;
	pos[2] = 0.0;
	news->Set_pos(pos);
	news->Set_chord(0.55);
	news->Set_ainc(2.5);
	news->Set_Nspan(5);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("JS.dat"));
	W.init_section(*news);
	//2
	news = new section;
	pos[0] = -0.065;
	pos[1] = 0.04;
	pos[2] = 0.0;
	news->Set_pos(pos);
	news->Set_chord(0.4);
	news->Set_ainc(2.5);
	news->Set_Nspan(3);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NACA0030.dat"));
	W.append_section(*news);
	//3
	news = new section;
	pos[0] = 0.0;
	pos[1] = 0.0648;
	pos[2] = 0.0;
	news->Set_pos(pos);
	news->Set_chord(0.30);
	news->Set_ainc(2.5);
	news->Set_Nspan(25);
	news->Set_Sspace(1);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NF.dat"));
	W.append_section(*news);
	//4
	news = new section;
	pos[0] = 0.1083 + houlue;
	pos[1] = 1.5916;
	pos[2] = 0.1550;
	news->Set_pos(pos);
	news->Set_chord(0.3);
	news->Set_ainc(-0.5);
	news->Set_Nspan(8);
	news->Set_Sspace(1);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NF.dat"));
	W.append_section(*news);

	//5
	news = new section;
	pos[0] = 0.2513 + houlue + yishaohoulue;
	pos[1] = 1.7448;
	pos[2] = 0.0188;
	news->Set_pos(pos);
	news->Set_chord(0.1);
	news->Set_ainc(0.0);
	news->Set_Nspan(8);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NF.dat"));
	W.append_section(*news);


	st.set_name(std::string("vsta"));
	st.set_index(4);
	st.set_angle(0);
	st.set_Nchord(11);

	//1
	news = new section;
	pos[0] = 0.45;
	pos[1] = 0.0;
	pos[2] = 0.0;
	news->Set_pos(pos);
	news->Set_chord(0.22);
	news->Set_ainc(0.0);
	news->Set_Nspan(10);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NACA0012.dat"));
	st.init_section(*news);
	//2
	news = new section;
	pos[0] = 0.65;
	pos[1] = 0.23;
	pos[2] = -0.0002;
	news->Set_pos(pos);
	news->Set_chord(0.08);
	news->Set_ainc(-0.5);
	news->Set_Nspan(10);
	news->Set_Sspace(0);
	news->Set_afil_type(1);
	news->Set_afil_afilname(std::string("NACA0012.dat"));
	st.append_section(*news);

	return;
}
void round_build(std::string str)
{
	file_oper F;
	//CreateDirectory(str.c_str(), NULL);
	string temp = "";
	string avlname = str;
	string runname = str;
	string cmdname = "";
	string inname = str;
	string stname = str;
	cmdname.append(str);
	inname.append("\\cac.in");
	cmdname.append("\\avl.cmd");
	runname.append("\\test.run");
	double d1 = 0;
	double d2 = 0;
	for (d1 = 0; d1 <= 0; d1 += 0.02)
	{
		for (d2 = -0.3; d2 <= -0.1; d2 += 0.02)
		{
			avlname = str;
			stname = str;
			temp = "";
			temp.append("d1_");
			temp.append(to_string(d1));
			temp.append("d2_");
			temp.append(to_string(d2));
			v.set_name(temp);
			W = *(new wing);
			st = *(new sta);
			draw_round(d1, d2);
			F.build_avl(str, v, W, st);
			avlname.append("\\");
			avlname.append(temp);
			avlname.append(".avl");
			stname.append("\\");
			stname.append(temp);
			cout << cmdname.c_str() << endl;
			F.build_cacfile(str, avlname, runname,stname);
			SetCurrentDirectory(str.c_str());
			system(cmdname.c_str());
			//F.build_run(str, v);
			//delete &W;
			//delete &st;
		}
	}

}
void round_build2(std::string str)
{
	file_oper F;
	//RemoveDirectory(str.c_str());
	//CreateDirectory(str.c_str(), NULL);
	string temp = "";
	string avlname = str;
	string runname = str;
	string cmdname = str;
	string inname = str;
	string stname = str;
	inname.append("\\cac.in");
	cmdname.append("\\avl.cmd");
	runname.append("\\test.run");
	double d1 = 0;
	double d2 = 0;
	for (d1 = 0.02; d1 <= 0.02; d1 += 0.02)
	{
		for (d2 = -0.3; d2 <= -0.1; d2 += 0.02)
		{
			avlname = str;
			stname = str;
			temp = "";
			temp.append("d1_");
			temp.append(to_string(d1));
			temp.append("d2_");
			temp.append(to_string(d2));
			v.set_name(temp);
			W = *(new wing);
			st = *(new sta);
			draw_round(d1, d2);
			F.build_avl(str, v, W, st);
			avlname.append("\\");
			avlname.append(temp);
			avlname.append(".avl");
			stname.append("\\");
			stname.append(temp);
			//cout << cmdname.c_str() << endl;
			F.build_cacfile(str, avlname, runname,stname);
			SetCurrentDirectory(str.c_str());
			system(cmdname.c_str());
			//F.build_run(str, v);
			//delete &W;
			//delete &st;
		}
	}

}
int main(int args, char argv[])
{

	v.set_Xref(0.131);
	v.set_Yref(0.0);
	v.set_Zref(0.04);
	v.set_density(1.1655);
	v.set_I(1.57, 0.048, 1.598, 0, 0, 0.003);
	v.set_Sref(1.013);
	v.set_Cref(0.294);
	v.set_Bref(3.49);
	//W.fresh_data();
	//W.updata2var(v);
	v.fresh_var();
	string str = { "D:\\MY_Flight_Dynamics\\double_houlue" };
	string s1 = "D:\\MY_Flight_Dynamics\\double_houlue2";
	string s2 = "D:\\MY_Flight_Dynamics\\double_houlue3";
	//round_build(s1);
	thread t1(round_build, s1);
	thread t2(round_build2, s2);

	t1.join();
	t2.join();
	system("pause");
	return 0;
}
