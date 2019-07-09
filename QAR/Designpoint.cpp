#include "Designpoint.h"
void Flight::Designpoint::Cal_Quality()
{
	lon_frequency= abs(eig_lon.array());
	lon_damping = -eig_lon.array().real() / lon_frequency;
	lon_timeconstant = 1 / (lon_damping * lon_frequency);
	lat_frequency = abs(eig_lat.array());
	lat_damping = -eig_lat.array().real() / lat_frequency;
	lat_timeconstant = 1 / (lat_damping * lat_frequency);
	damp_lon << lon_damping, lon_frequency, lon_timeconstant;
	damp_lat << lat_damping, lat_frequency, lat_timeconstant;
	/*
		f = abs(s);
	wn(idx) = f;
	z(idx) = -real(s). / f;

	tau = 1. / (z.*wn);
	tau(isinf(tau)) = inf;*/
}
double Flight::Designpoint::Atmosphere(double height)
{
	double r0 = 6356766;//单位m
	double hp = height / (1 + height / r0);
	double density;
	double R = 287.053; // 空气常数，单位J / (kg * K)
	double g0 = 9.80665;
	if (hp <= 11000)
		density = 0.101325e6 / pow((R * 288.15) * (1 + (-0.0065 / 288.15) * (hp - 0)), ((-g0 / R / (-0.0065)) - 1));
	else if (hp <= 20000)
		density = 0.226321e5 / (R * 216.65) * exp(-g0 / (R * 216.65) * (hp - 11000));
	else if (hp <= 32000)
		density = 0.547488e4 / pow((R * 216.65) * (1 + (0.001 / 216.65) * (hp - 20000)), ((-g0 / R / 0.001) - 1));	
	else if (hp <= 47000)
		density = 0.868018e3 / pow((R * 228.65) * (1 + (0.0028 / 228.65) * (hp - 32000)), ((-g0 / R / 0.0028) - 1));
	else if (hp <= 51000)
		density = 0.110906e3 / (R * 270.65) * exp(-g0 / (R * 270.65) * (hp - 47000));
	else if (hp <= 71000)
		density = 0.669387e2 / pow((R * 270.65) * (1 + (-0.0028 / 270.65) * (hp - 51000)), ((-g0 / R / (-0.0028)) - 1));
	else
		density = 0.395641 * 10 / pow((R * 214.65) * (1 + (-0.002 / 214.65) * (hp - 71000)), ((-g0 / R / (-0.002)) - 1));
	return density;
}

