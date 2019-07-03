#pragma once
#include <fstream>
#include <iostream> 
#include <string>
#include "var.h"
#include "wing.h"
#include "section.h"
#include "sta.h"
#pragma warning(disable:4996)
using namespace std;
class file_oper
{
protected:
	FILE* file;
	ofstream ofile;
public:
	void build_file(string filename);
	void finish_file();
	void writefile(string str,int movement);
	void writefile(string str);
	void build_run(string filepath,var v);
	void build_avl(string filepath,var v,wing w,sta st);
	void build_cacfile(string filepath, string avlname,string runname,string stname);
	void build_cmd(string filepath, string);
	FILE* get_file_point(void);
};