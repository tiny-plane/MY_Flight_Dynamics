#pragma once
#include <string> 
class control_surface
{
private:
	std::string name = "elevator";
	double gain = 1;
	double xhinge = 0;
	double xyzhvec[3] = { 0 , 0, 0 };
	double sgndup = 1;
public:
	control_surface(std::string& name, double gain, double xhinge, double xyzhvec[3], int sgndup) :name(name), gain(gain), xhinge(xhinge), sgndup(sgndup) {
		this->xyzhvec[0] = xyzhvec[0];
		this->xyzhvec[1] = xyzhvec[1];
		this->xyzhvec[2] = xyzhvec[2];
	}
	~control_surface();
	const std::string& Get_name()const
	{
		return this->name;
	}
	const double& Get_gain()const
	{
		return this->gain;
	}
	const double& Get_xhinge()const
	{
		return this->xhinge;
	}
	const double* Get_xyzhvec()const
	{
		return this->xyzhvec;
	}
	const double& Get_sgndup()const
	{
		return this->sgndup;
	}
	void Set_name(std::string& name)
	{
		this->name = name;
	}
	void Set_xhinge(double xhinge)
	{
		this->xhinge = xhinge;
	}
	void Set_gain(double gain)
	{
		this->gain = gain;
	}
	void Set_sgndup(double sgndup)
	{
		this->sgndup = sgndup;
	}
	void Set_xyzhvec(double xyzhvec[3])
	{
		this->xyzhvec[0] = xyzhvec[0];
		this->xyzhvec[1] = xyzhvec[1];
		this->xyzhvec[2] = xyzhvec[2];
	}

};