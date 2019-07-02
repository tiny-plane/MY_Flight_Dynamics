#pragma once
#include <fstream>
#include <iostream> 
#include <string>
#include "var.h"
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
	void build_avl(string filepath);
	FILE* get_file_point(void);
};