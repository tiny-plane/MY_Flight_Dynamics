#pragma once
#include <math.h>
#include <Eigen\Eigenvalues>
#include <Eigen\Dense>	
#include <vector>
namespace Flight
{
	typedef std::vector <Eigen::Vector4d> control_vector;
	class Designpoint//QAR的一个属性,内置一些数据分析
	{
	private:
		double height = 500;
		double velocity = 10;
		double density = 1.16;
		double q_dyn = 50.7428;
		double Tv = -0.5;
		int lon_controlsurface_num = 1;
		int lat_controlsurface_num = 1;
		Eigen::Matrix4d A_lon;
		Eigen::Matrix4d A_lat;
		Eigen::Vector4cd eig_lon, eig_lat;
		Eigen::Array4d lon_damping, lon_frequency, lon_timeconstant, lat_damping, lat_frequency, lat_timeconstant;
		Eigen::Array<double, 4, 3> damp_lon,damp_lat;
		control_vector B_lon;
		control_vector B_lat;
	public:
		void Cal_Quality();
		void Set_A_lon(Eigen::Matrix4d A_lon)
		{
			this->A_lon = A_lon;
		}
		Eigen::Matrix4d Get_A_lon()
		{
			return this->A_lon;
		}
		void Set_A_lat(Eigen::Matrix4d A_lat)
		{
			this->A_lat = A_lat;
		}
		Eigen::Matrix4d Get_A_lat()
		{
			return this->A_lat;
		}
		void Set_height(double height)
		{
			this->height = height;
		};
		double Get_height()
		{
			return height;
		};
		void Set_velocity(double velocity)
		{
			this->velocity = velocity;
		};
		double Get_velocity()
		{
			return velocity;
		};
		void Set_density(double density)
		{
			this->density = density;
		};
		double Get_density()
		{
			return density;
		};
		void Set_q_dyn(double q_dyn)
		{
			this->q_dyn = q_dyn;
		};
		double Get_q_dyn()
		{
			return q_dyn;
		};
		void Set_Tv(double Tv)
		{
			this->Tv = Tv;
		};
		double Get_Tv()
		{
			return Tv;
		};
		static double Atmosphere(double height);
		static double Velocity(double density, double mass, double Sref, double CL)
		{
			return(sqrt(mass * 9.8 * 2 / density / Sref / CL));
		}
		Eigen::Vector4cd Get_eig_lon()
		{
			return eig_lon;
		};
		Eigen::Vector4cd Get_eig_lat()
		{
			return eig_lat;
		};
		void Set_eig_lon(Eigen::Vector4cd eig_lon)
		{
			this->eig_lon = eig_lon;
		};
		void Set_eig_lat(Eigen::Vector4cd eig_lat)
		{
			this->eig_lat = eig_lat;
		};
		Eigen::Array4d Get_lon_damping()
		{
			return lon_damping;
		};
		Eigen::Array4d Get_lon_frequency()
		{
			return lon_frequency;
		}
		Eigen::Array4d Get_lon_timeconstant()
		{
			return lon_timeconstant;
		}
		Eigen::Array4d Get_lat_damping()
		{
			return lat_damping;
		};
		Eigen::Array4d Get_lat_frequency()
		{
			return lat_frequency;
		}
		Eigen::Array4d Get_lat_timeconstant()
		{
			return lat_timeconstant;
		}
		Eigen::Array<double, 4, 3> Get_damp_lon()
		{
			return damp_lon;
		}
		Eigen::Array<double, 4, 3> Get_damp_lat()
		{
			return damp_lat;
		}
		//lon_damping, lon_frequency, lon_timeconstant, lat_damping, lat_frequency, lat_timeconstant;
	};
}