#include <iostream>

using namespace std;

void minMaxRep(int a[], size_t size, int& mn, size_t& in, int& mx, size_t& ix) {
	int biggest = a[0];
	int lowest = a[0];
	int minWyst = 0;
	int maxWyst = 0;
	for (int i = 0; i < size; ++i) {

		if (a[i] > biggest) {
			biggest = a[i];
		}

		if (biggest == a[i]) {
			maxWyst++;
		}

		if (a[i] < lowest) {
			lowest = a[i];
		}

		if (a[i] == lowest) {
			minWyst++;
		}

	}
	ix = maxWyst;
	in = minWyst;
	mx = biggest;
	mn = lowest;

}
int main() {
	int a[]{ 2, 3, 4, 2, 7, 4, 7, 2 };
	size_t size = sizeof(a) / sizeof(*a);
	int mn = 0, mx = 0;
	size_t in = 0, ix = 0;
	minMaxRep(a, size, mn, in, mx, ix);
	cout << "Array:  [";
	for (size_t i = 0; i < size; ++i)
	{
		cout << a[i] << " ";
	}

	cout << "] \n";
	cout << "Min = " << mn << " " << in << " times\n";
	cout << "Max = " << mx << " " << ix << " times\n";

	return 0;
}
