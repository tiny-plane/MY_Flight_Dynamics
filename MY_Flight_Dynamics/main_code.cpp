#include "main_code.h"


bool Draw(wing& W , sta& st)
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
	delete(news);
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
	delete(news);
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
	delete(news);
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
	delete(news);

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
	delete(news);


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
	delete(news);
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
	delete(news);
	return false;
}

void draw_round(double houlue, double yishaohoulue, double shangfan, double yishaoshangfan, wing& W, sta& st)
{
	double pos[3] = { 0.0 ,0.0 , 0.0 };

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
	pos[2] = 0.1550 + shangfan;
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
	pos[2] = 0.0188 + shangfan + yishaoshangfan;
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
void round_build(std::string str, int threadnum)
{
	var v;
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

	file_oper F;

	int filecount = 1000;
	string temp = "";
	wing W;

	sta st;

	W = *(new wing);
	st = *(new sta);
	wing* wpoint = &W;
	sta* stpoint = &st;

	string newdir = str;
	newdir.append(to_string(threadnum));
	string avlexestr = str;
	avlexestr.append("\\avl.exe");
	string JSdatstr = str;
	JSdatstr.append("\\JS.dat");
	string NACA0012str = str;
	NACA0012str.append("\\NACA0012.dat");
	string NACA0030str = str;
	NACA0030str.append("\\NACA0030.dat");
	string NFstr  = str;
	NFstr.append("\\NF.dat");
	string testrunstr = str;
	testrunstr.append("\\test.run");

	int dircount = 0;
	double hou1 = 0;
	double threadend = 0;
	double hou2 = 0;
	double shang1 = 0;
	double shang2 = 0;
	switch (threadnum)
	{
	case 1:
		threadend = -0.1;
		break;
	case 2:
		threadend = 0.05;
		break;
	case 3:
		threadend = 0.2;
		break;
	case 4:
		threadend = 0.35;
	default:
		break;
	}
	int cout = 1;
	string name = "";
	for (hou1 = threadend; hou1 <= threadend + 0.1; hou1 += 0.05)
	{//0.1 0.05 2     2
		for (hou2 = -0.4; hou2 <= 0.4; hou2 += 0.05)
		{//0.8 0.05 16     9
			for (shang1 = -0.1; shang1 <= 0.2; shang1 += 0.05)
			{// 0.25 0.05 5     4
				for (shang2 = -0.1; shang2 <= 0.2; shang2 += 0.05)
				{// 0.3 0.05 6    4

					if (filecount >= 100)
					{
						newdir = str;
						newdir.append(to_string(threadnum));
						newdir.append("_");
						newdir.append(to_string(dircount));
						CreateDirectoryA(newdir.c_str(),NULL);
						SetCurrentDirectory(newdir.c_str());
						string newaavlexestr = newdir;
						newaavlexestr.append("\\avl.exe");
						string newJSdatstr = newdir;
						newJSdatstr.append("\\JS.dat");
						string newNACA0012str = newdir;
						newNACA0012str.append("\\NACA0012.dat");
						string newNACA0030str = newdir;
						newNACA0030str.append("\\NACA0030.dat");
						string newNFstr = newdir;
						newNFstr.append("\\NF.dat");
						string newtestrunstr = newdir;
						newtestrunstr.append("\\test.run");
						
						CopyFileA(avlexestr.c_str(),newaavlexestr.c_str(), FALSE);
						CopyFileA(JSdatstr.c_str(), newJSdatstr.c_str(), FALSE);
						CopyFileA(NACA0012str.c_str(), newNACA0012str.c_str(), FALSE);
						CopyFileA(NACA0030str.c_str(), newNACA0030str.c_str(), FALSE);
						CopyFileA(NFstr.c_str(), newNFstr.c_str(), FALSE);
						CopyFileA(testrunstr.c_str(), newtestrunstr.c_str(), FALSE);
						F.build_cmd(newdir);

						dircount++;
						filecount = 0;
					}
					//std::cout << "thread: "<< threadnum << "  dir: " << dircount <<"   filecount: "<< hou1 << " count: "<<cout<<std:: endl;
					string avlname = newdir;
					string runname = newdir;
					string cmdname = "";
					string inname = newdir;
					string stname = newdir;
					
					cmdname.append(newdir);
					inname.append("\\cac.in");
					cmdname.append("\\avl.cmd");
					runname.append("\\test.run");

					temp = "";
					temp.append("winghoulue_");
					temp.append(to_string(hou1));
					temp.append("_");
					temp.append("wingtiphoulue_");
					temp.append(to_string(hou2));
					temp.append("wingshangfan_");
					temp.append(to_string(shang1));
					temp.append("wingtipshangfan_");
					temp.append(to_string(shang2));
					name = "";
					name.append(to_string(cout));
					v.set_name(name);

					wpoint = NULL;
					stpoint = NULL;
					wpoint = new wing;
					stpoint = new sta;
					W = *wpoint;
					st = *stpoint;
					

					
					draw_round(hou1, hou2, shang1, shang2,W ,st);
					//std::cout << F.build_avl(newdir, v, W, st, temp) << std::endl;
					avlname.append("\\");
					avlname.append(to_string(cout));
					avlname.append(".avl");
					stname.append("\\");
					stname.append(to_string(cout));
					F.build_cacfile(newdir, avlname, runname, stname);
					system(cmdname.c_str());
					cout++;
					filecount++;
				}
			}
		}
	}
}

int main(int args, char argv[])
{

	string str = { "D:\\MY_Flight_Dynamics\\double_houlue" };

	thread t1(round_build, str, 1);
	
	thread t2(round_build, str, 2);
	
	thread t3(round_build, str, 3);
	
	thread t4(round_build, str, 4);
	
	//round_build(str,1);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	system("pause");
	return 0;
}
