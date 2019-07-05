#pragma once
#include <iostream>
#include <math.h>
#include "var.h"
#include "surface.h"
#include "wing.h"
#include "sta.h"
#include "file_oper.h"
#include <string>
#include <fstream>
#include<windows.h>
#include <thread>
#pragma warning(disable:4996)
template<class T>
int length(T& arr);

int main(int args, char argv[]);
bool Draw(wing& W,sta& st);
bool Write2avl(void);
bool Readfromavl;