#include <iostream>

using namespace std;

void ord3(double& a, double& b, double& c); 
void ord3(double* a, double* b, double* c);
void getMinMax(const double& a, const double& b, const double& c, const double*& pMin, const double*& pMax); 
void getMinMax(const double* a, const double* b, const double* c, const double** pMin, const double** pMax);

void printOrd(const double* a, const double* b, const double* c) 
{ 
	using std::cout;
	using std::endl;
	cout << *a << " " << *b << " " << *c << endl; 
}

void printMinMax(const double* pmn, const double* pmx) 
{ 
	using std::cout;
	using std::endl; std::cout << "Min = " << *pmn << "; " << "Max = " << *pmx << std::endl; 
}

// Zadanie 02
const double* aver(const double* arr, size_t size, double& average);
void hello();

int main() {
	double a, b, c;
	const double* pMin, * pMax; 
	a = 2; 
	b = 1; 
	c = 3; 
	ord3(a, b, c); 
	//printOrd(&a, &b, &c); 
	a = 3;
	b = 2; 
	c = 1; 
	ord3(&a, &b, &c);
	printOrd(&a, &b, &c);
	a = -1;
	b = -1;
	c = 1; 
	ord3(&a, &b, &c);
	printOrd(&a, &b, &c); 
	a = 2;
	b = 3;
	c = 1; 
	getMinMax(a, b, c, pMin, pMax);
	printMinMax(pMin, pMax);
	a = 3;
	b = 1;
	c = 2;
	getMinMax(&a, &b, &c, &pMin, &pMax);
	printMinMax(pMin, pMax);
	a = 3;
	b = 3; 
	c = -1;
	getMinMax(&a, &b, &c, &pMin, &pMax); 
	printMinMax(pMin, pMax);

	// Zadanie 02 
	double arr[] = { 1, 7, 5, 4, 3, 2 };
	size_t size = sizeof( arr ) / sizeof( arr[0] );
	double average = 0;
	const double* p = aver( arr, size, average );
	//cout << *p << " " << average << endl;

	hello();
	return 0;
}

void ord3(double& a, double& b, double& c) // 2, 1, 3
{
	double max = a;
	double middle = b;
	double lowest = c;
	if (a > b && a > c)
	{
		max = a;

		if (b > c)
		{
			middle = b;
			lowest = c;
		}
				
	}

	else if (b > a && b > c) 
	{
		max = b;

		if (a > c)
		{
			middle = a;
			lowest = c;
		}
	}

	else
	{
		max = c;
		if (a > b) 
		{
			middle = a;
			lowest = b;
		}
		
	}
	
	cout << "Max " << max << " middle " << middle << " lowest " << lowest << endl;
}

void ord3(double* a, double* b, double* c)
{
	double max = *a;
	double middle = *b;
	double lowest = *c;
	if (a > b && a > c)
	{
		max = *a;

		if (b > c)
		{
			middle = *b;
			lowest = *c;
		}

	}

	else if (b > a && b > c)
	{
		max = *b;

		if (a > c)
		{
			middle = *a;
			lowest = *c;
		}
	}

	else
	{
		max = *c;
		if (a > b)
		{
			middle = *a;
			lowest = *b;
		}

	}

	cout << "Max " << max << " middle " << middle << " lowest " << lowest << endl;
}

void getMinMax(const double& a, const double& b, const double& c, const double*& pMin, const double*& pMax)
{
	double max = a;
	double middle = b;
	double lowest = c;
	
	if (a > b && a > c)
	{
		max = a;

		if (b > c)
		{
			middle = b;
			lowest = c;
		}

	}

	else if (b > a && b > c)
	{
		max = b;

		if (a > c)
		{
			middle = a;
			lowest = c;
		}
	}

	else
	{
		max = c;
		if (a > b)
		{
			middle = a;
			lowest = b;
		}

	}

	//pMin = lowest;
	//pMax = max;
	//max = *pMax;
	cout << "PMin " << &*pMin << endl;
	cout << " PMax " << pMax << endl;

	cout << "Max " << max << " lowest " << lowest << endl;
}

void getMinMax(const double* a, const double* b, const double* c, const double** pMin, const double** pMax)
{

}

const double* aver(const double* arr, size_t size, double& average)
{
	double sum = 0;
	double srednia = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	
	if (size % 2 == 0)
	{
		srednia = arr[size / 2];
	}
	
	average = sum / size;
	return &srednia;
	
}