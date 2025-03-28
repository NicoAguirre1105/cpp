#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct OutOfMemory {};
struct OutOfRange {};

struct Vector {
	int size;
	double* ar;
	Vector(int n)  {
		if (n > 2000000000) throw OutOfMemory();
		size = n;
		ar = new double[n];
	}
	~Vector() { delete[] ar; }
	double& operator[] (int i) {
		if (i < 0 || i >= size) throw OutOfRange();
		return ar[i];
	}
};

int main()
{
	int n, i;
	double d;
	try {
        cout << "Enter the size of the vector: ";
		cin >> n;
		Vector v(n);
        cout << "Enter the index and the value: ";
		cin >> i >> d;
		v[i] = d;
		
	}
	catch (OutOfMemory) {
		cerr << "ERROR: Out of memory" << endl;
		return EXIT_FAILURE;
	}
	catch (OutOfRange) {
		cerr << "ERROR: Index out of range" << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}