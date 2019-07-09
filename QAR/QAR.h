#pragma once
#include "Propeller.h"
#include "Designpoint.h"
#include "interpolation.h"
#include "Para.h"
#include "Datast.h"
#include "elevator.h"
#include "propellerthrust.h"
#include "propellerdifferetialmotion.h"
#include "aileron.h"
#include "Nothrust.h"
#include "Propeller.h"
#include <iostream>

namespace Flight
{
	template <class T>
	class QAR
	{
	private:
		Datast datast;
		Para para;
		T thrust;
		Designpoint designpoint;
	public:
		QAR(Datast datast, Para para, T thrust) :datast(datast), para(para), thrust(thrust) {};
		template <class TT>
		void Cal_A(double height) {
			std::cout << "Not A Thurst Type!" << std::endl;
		}
		template<>void Cal_A<Nothrust>(double height) {
			designpoint.Set_height(height);
			designpoint.Set_density(Flight::Designpoint::Atmosphere(height));
			designpoint.Set_velocity(Flight::Designpoint::Velocity(designpoint.Get_density(), para.Get_mass(), para.Get_Sref(), datast.Get_CL()));
			designpoint.Set_q_dyn(0.5 * designpoint.Get_density() * designpoint.Get_velocity() * designpoint.Get_velocity());
			//designpoint.Set_Tv(-0.5);
			Eigen::Matrix4d A_lon, A_lat;
			double Madot, Xv, Xa, Malpha, Mq, Zv, Za, Mv;
			double* Inertia = para.Get_Inertia();
			Madot = datast.Get_Cmadot() * para.Get_Cref() * para.Get_Cref() * designpoint.Get_q_dyn() * para.Get_Sref() / 2 / designpoint.Get_velocity() / *(Inertia + 4);
			Xv = designpoint.Get_Tv() * cos(datast.Get_alpha() / 57.3) / para.Get_mass() - 2 * designpoint.Get_q_dyn() * datast.Get_CD() * para.Get_Sref() / para.Get_mass() / designpoint.Get_velocity();
			Xa = -designpoint.Get_q_dyn() * para.Get_Sref() * (datast.Get_CD() * tan(datast.Get_alpha() / 57.3) + datast.Get_CDa()) / para.Get_mass();
			Malpha = datast.Get_Cma() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Cref() / *(Inertia + 4);
			Mq = datast.Get_Cmq() * para.Get_Cref() / 2 / designpoint.Get_q_dyn() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Cref() / *(Inertia + 4);
			Zv = designpoint.Get_Tv() * sin(datast.Get_alpha() / 57.3) / para.Get_mass() / designpoint.Get_q_dyn() + 2 * datast.Get_CL() * designpoint.Get_q_dyn() * para.Get_Sref() / para.Get_mass() / designpoint.Get_velocity() / designpoint.Get_velocity();
			Za = (datast.Get_CD() + datast.Get_CLa()) * designpoint.Get_q_dyn() * para.Get_Sref() / para.Get_mass() / designpoint.Get_velocity();
			Mv = 2 * datast.Get_Cm() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Cref() / designpoint.Get_velocity() / *(Inertia + 4);
			A_lon <<
				Xv, 9.8 + Xa, 0, -9.8,
				-Zv, -Za, 1, 0,
				Mv - Madot * Zv, Malpha - Za * Madot, Madot + Mq, 0,
				0, 0, 1, 0;
			designpoint.Set_A_lon(A_lon);
			double Yb, Yp, Yr, Lbb, Lpp, Lrr, Nbb, Npp, Nrr, Lb, Lp, Lr, Nb, Np, Nr;
			Yb = datast.Get_CYb() * designpoint.Get_q_dyn() * para.Get_Sref() / para.Get_mass() / designpoint.Get_velocity();
			Yp = datast.Get_CYp() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Bref() / 2 / para.Get_mass() / designpoint.Get_velocity() / designpoint.Get_velocity();
			Yr = datast.Get_CYr() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Bref() / 2 / para.Get_mass() / designpoint.Get_velocity() / designpoint.Get_velocity();
			Lbb = datast.Get_Clb() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Bref();
			Lpp = datast.Get_Clp() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Bref() * para.Get_Bref() / 2 / designpoint.Get_velocity();
			Lrr = datast.Get_Clr() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Bref() * para.Get_Bref() / 2 / designpoint.Get_velocity();
			Nbb = datast.Get_Cnb() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Bref();
			Npp = datast.Get_Cnp() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Bref() * para.Get_Bref() / 2 / designpoint.Get_velocity();
			Nrr = datast.Get_Cnr() * designpoint.Get_q_dyn() * para.Get_Sref() * para.Get_Bref() * para.Get_Bref() / 2 / designpoint.Get_velocity();
			Lb = (Lbb + *(Inertia + 2) / *(Inertia + 8) * Nbb) / (*Inertia - *(Inertia + 2) * *(Inertia + 2) / *(Inertia + 8));
			Lp = (Lpp + *(Inertia + 2) / *(Inertia + 8) * Npp) / (*Inertia - *(Inertia + 2) * *(Inertia + 2) / *(Inertia + 8));
			Lr = (Lrr + *(Inertia + 2) / *(Inertia + 8) * Nrr) / (*Inertia - *(Inertia + 2) * *(Inertia + 2) / *(Inertia + 8));
			Nb = (Nbb + *(Inertia + 2) / *(Inertia)* Lbb) / (*(Inertia + 8) - *(Inertia + 2) * *(Inertia + 2) / *(Inertia));
			Np = (Npp + *(Inertia + 2) / *(Inertia)* Lpp) / (*(Inertia + 8) - *(Inertia + 2) * *(Inertia + 2) / *(Inertia));
			Nr = (Nrr + *(Inertia + 2) / *(Inertia)* Lrr) / (*(Inertia + 8) - *(Inertia + 2) * *(Inertia + 2) / *(Inertia));
			A_lat <<
				Yb, datast.Get_alpha() / 57.3 + Yp, Yr - 1, 9.8 * cos(datast.Get_alpha() / 57.3) / designpoint.Get_velocity(),
				Lb, Lp, Lr, 0,
				Nb, Np, Nr, 0,
				0, 1, tan(datast.Get_alpha() / 57.3), 0;
			designpoint.Set_A_lat(A_lat);
			Eigen::EigenSolver<Eigen::Matrix4d> lon(A_lon);
			designpoint.Set_eig_lon(lon.eigenvalues());
			Eigen::EigenSolver<Eigen::Matrix4d> lat(A_lat);
			designpoint.Set_eig_lat(lat.eigenvalues());
			designpoint.Cal_Quality();
		}
		template<>void Cal_A<propellerthrust>(double height) {}
		void run(double height)
		{
			Cal_A<T>(height);
		}
		const Designpoint& Get_designpoint()
		{
			return this->designpoint;
		}
	};
}