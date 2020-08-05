#pragma once
#include <iostream>
class Resistor
{
	private: 
		double resistance;

	public:	
		Resistor();
		Resistor(double r);
		const double r();
		void r(double r);
		

		Resistor operator + (Resistor r1);
		Resistor operator * (Resistor r1);
		friend std::ostream& operator << (std::ostream& o, Resistor r1);


};

