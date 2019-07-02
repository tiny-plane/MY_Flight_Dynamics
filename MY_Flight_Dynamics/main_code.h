#pragma once
#include <iostream>
#include <math.h>
#include "var.h"
#include "surface.h"
#include "wing.h"
#include "file_oper.h"
#include <string>
#include <fstream>
#pragma warning(disable:4996)
template<class T>
int length(T& arr);

var v;
wing W;
int main(int args, char argv[]);
bool Draw(void);
bool Write2avl(void);
bool Readfromavl;