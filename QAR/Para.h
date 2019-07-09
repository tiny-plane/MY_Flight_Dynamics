#pragma once
namespace Flight
{
	class Para
	{
	private:
		double mass = 1;
		double Sref = 1;
		double Cref = 1;
		double Bref = 1;
		double Inertia[3][3] = { {1,0,1},{0 ,1 ,0}, {1,0,1} };
	public:
		void Readfromavlrun();
		bool Readfromkeyboard();
		void Set_mass(double mass)
		{
			this->mass = mass;
		};
		double Get_mass()
		{
			return mass;
		};
		void Set_Sref(double Sref)
		{
			this->Sref = Sref;
		};
		double Get_Sref()
		{
			return Sref;
		};
		void Set_Cref(double Cref)
		{
			this->Cref = Cref;
		};
		double Get_Cref()
		{
			return Cref;
		};
		void Set_Bref(double Bref)
		{
			this->Bref = Bref;
		};
		double Get_Bref()
		{
			return Bref;
		};
		void Set_Inertia(double Inertia[3][3])
		{
			this->Inertia[0][0] = Inertia[0][0];
			this->Inertia[0][1] = Inertia[0][1];
			this->Inertia[0][2] = Inertia[0][2];
			this->Inertia[1][0] = Inertia[1][0];
			this->Inertia[1][1] = Inertia[1][1];
			this->Inertia[1][2] = Inertia[1][2];
			this->Inertia[2][0] = Inertia[2][0];
			this->Inertia[2][1] = Inertia[2][1];
			this->Inertia[2][2] = Inertia[2][2];
		};
		double* Get_Inertia()
		{
			return &Inertia[0][0];
		};
	};
}