#pragma once
namespace Flight
{
	enum thrusttype { Propellerthrust,None };
	class Thrust
	{
	protected:
		thrusttype type = Propellerthrust;
	public:
		Thrust(thrusttype type):type(type){}
	};
}