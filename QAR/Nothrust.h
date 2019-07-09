#pragma once
#include "Thrust.h"
namespace Flight
{
	class Nothrust: public Thrust
	{
	public:
		Nothrust() :Thrust(None) {  }
	};
}