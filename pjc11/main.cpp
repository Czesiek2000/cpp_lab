#include <iostream>
#include "Resistor.h";

int main() {

	Resistor r1, r2{ 6 };
	r1.r(-1);
	std::cout << "r1.resistance " << r1.r() << " r2.resistance " << r2.r() << std::endl;
	try {
		if (r1.r() < 0) {
			throw r1.r();
		}

		try {
			if (r2.r() < 0) {
				throw r2.r();
			}
			std::cout << (r1 + r2) << " " << (r1 * r2) << std::endl;
		}
		catch (double r2) {
			std::cout << "Wartosc r2 jest mniejsza od 0";
		}
		
	}catch (double res) {
		std::cout << "wartosc r1 jest mniejsza od 0";
	}

	
	return 0;
}
