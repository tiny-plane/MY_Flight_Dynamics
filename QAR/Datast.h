#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
namespace Flight
{
	class Datast
	{
	private:
		double alpha;//Ñ²º½½Ç¶È£¬µ¥Î»deg
		double CL, CD;
		double Cm;
		double CLa, CDa, Cma;
		double CYb, Clb, Cnb;
		double CYp, Clp, Cnp;
		double CLq, Cmq;
		double CYr, Clr, Cnr;
		double Cmadot;
		double elevator;
	public:
		Datast();
		Datast(std::string input);
		void Readfromavloutput(std::string input);
		bool Readfromkeyboard();
		void Set_alpha(double alpha)
		{
			this->alpha = alpha;
		};
		double Get_alpha()
		{
			return alpha;
		};
		void Set_elevator(double elevator)
		{
			this->elevator = elevator;
		};
		double Get_elevator()
		{
			return elevator;
		};
		void Set_CL(double CL)
		{
			this->CL = CL;
		};
		double Get_CL()
		{
			return CL;
		};
		void Set_CD(double CD)
		{
			this->CD = CD;
		};
		double Get_CD()
		{
			return CD;
		};
		void Set_Cm(double Cm)
		{
			this->Cm = Cm;
		};
		double Get_Cm()
		{
			return Cm;
		};
		void Set_CLa(double CLa)
		{
			this->CLa = CLa;
		};
		double Get_CLa()
		{
			return CLa;
		};
		void Set_Cma(double Cma)
		{
			this->Cma = Cma;
		};
		double Get_Cma()
		{
			return Cma;
		};
		void Set_CYb(double CYb)
		{
			this->CYb = CYb;
		};
		double Get_CYb()
		{
			return CYb;
		};
		void Set_Clb(double Clb)
		{
			this->Clb = Clb;
		};
		double Get_Clb()
		{
			return Clb;
		};
		void Set_Cnb(double Cnb)
		{
			this->Cnb = Cnb;
		};
		double Get_Cnb()
		{
			return Cnb;
		};
		void Set_CYp(double CYp)
		{
			this->CYp = CYp;
		};
		double Get_CYp()
		{
			return CYp;
		};
		void Set_Clp(double Clp)
		{
			this->Clp = Clp;
		};
		double Get_Clp()
		{
			return Clp;
		};
		void Set_Cnp(double Cnp)
		{
			this->Cnp = Cnp;
		};
		double Get_Cnp()
		{
			return Cnp;
		};
		void Set_CLq(double CLq)
		{
			this->CLq = CLq;
		};
		double Get_CLq()
		{
			return CLq;
		};
		void Set_Cmq(double Cmq)
		{
			this->Cmq = Cmq;
		};
		double Get_Cmq()
		{
			return Cmq;
		};
		void Set_CYr(double CYr)
		{
			this->CYr = CYr;
		};
		double Get_CYr()
		{
			return CYr;
		};
		void Set_Clr(double Clr)
		{
			this->Clr = Clr;
		};
		double Get_Clr()
		{
			return Clr;
		};
		void Set_Cnr(double Cnr)
		{
			this->Cnr = Cnr;
		};
		double Get_Cnr()
		{
			return Cnr;
		};
		void Set_Cmadot(double Cmadot)
		{
			this->Cmadot = Cmadot;
		};
		double Get_Cmadot()
		{
			return Cmadot;
		};
		void Set_CDa(double CDa)
		{
			this->CDa = CDa;
		};
		double Get_CDa()
		{
			return CDa;
		};
	};
}