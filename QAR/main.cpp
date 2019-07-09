#include <iostream>
#include <fstream>
#include <Eigen\Dense>
#include "Datast.h"
#include "Designpoint.h"
#include "interpolation.h"
#include "Propeller.h"
#include "QAR.h"
#include "Nothrust.h"
#include "Thrust.h"

int main()
{
	/*Flight::Datast datast;
	datast.Set_alpha(2);
	datast.Set_CD(0.0354);
	datast.Set_CL(0.9264);
	datast.Set_Cm(0);
	datast.Set_CLq(10.6197);
	datast.Set_Cmq(-17.7321);
	datast.Set_CYp(-0.1269);
	datast.Set_CYr(0.0997);
	datast.Set_Clp(-0.789);
	datast.Set_Clr(0.2541);
	datast.Set_Cnp(-0.1012);
	datast.Set_Cnr(-0.0089);
	datast.Set_CDa(0.2329);
	datast.Set_CLa(6.4310);
	datast.Set_Cma(-1.4215);
	datast.Set_CYb(-0.1547);
	datast.Set_Clb(-0.0649);
	datast.Set_Cnb(0.0015);*/
	Flight::Datast datast("C:\\Users\\chen\\source\\repos\\MY_Flight_Dynamics\\x64\\Debug\\111.txt");
	datast.Set_Cmadot(0.3 * datast.Get_Cmq());
	datast.Set_CDa(0.2);
	Flight::Para para;
	double Inertia[3][3] = { {863.9,0,-8.4},{0,40.5,0},{-8.4,0,96.1} };
	para.Set_Bref(19.5);
	para.Set_Cref(0.78);
	para.Set_Sref(15.21);
	para.Set_mass(50);
	para.Set_Inertia(Inertia);
	Flight::Nothrust nothrust;
	Flight::QAR<Flight::Nothrust> qar(datast, para, nothrust);
	qar.run(500);
	Flight::Designpoint designpoint = qar.Get_designpoint();
	std::cout << designpoint.Get_eig_lat()<< std::endl;
	//std::cout << designpoint.Get_eig_lon() << std::endl
	//std::cout << designpoint.Get_eig_lat()[1].imag();
	//std::cout << abs(std::complex<double>(3 ,4));
	/*Eigen::Array4d a, b;
	a << 1, 2, 3, 4;
	b << 2, 3, 4, 5;
	std::cout << a * b;*/
	std::cerr << "ºáº½Ïò" << std::endl;
	std::cout << designpoint.Get_damp_lat() << std::endl;
	std::cerr << "×İÏò" << std::endl;
	std::cout << designpoint.Get_damp_lon() << std::endl;
	system("pause");
	return 0;
}
