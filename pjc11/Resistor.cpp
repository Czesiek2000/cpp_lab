#include "Resistor.h"

Resistor::Resistor() {
	this->resistance = 0;
};

Resistor::Resistor(double r) {
	this->resistance = r;
};

const double Resistor::r() {
	return this->resistance;
};
		
void Resistor::r(double res) {
	this->resistance += res;
};

Resistor Resistor::operator +(Resistor r1) {
	Resistor r;
	//std::cout << "r.resistance " << r.resistance << " resistance " << resistance << " r1.resitance " << r1.resistance << std::endl;
	r.resistance = resistance + r1.resistance;
	return r;
};
		
std::ostream& operator<<(std::ostream& o, Resistor r1) {
	//std::cout << "&o " << &o << " r1.resitance " << r1.resistance << std::endl;
	o << r1.resistance << " ";
	return o;
};

Resistor Resistor::operator * (Resistor r1) {
	Resistor r;
	//std::cout << "r.resistance " << 1 / (r.resistance) << " resistance " << 1 / (resistance) << " r1.resitance " << 1 / (r1.resistance) << std::endl;
	r.resistance = 1 / (resistance)+1 / (r1.resistance);
	Resistor tmp = 1 / (r.resistance);
	return tmp;
};
