#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct DivisionByZero {};

int div1(int x, int y) {
	if (y == 0) throw DivisionByZero();
	return x / y;
}

int main()
{
	int a, b, c;
    cout << "Enter two numbers: ";
	cin >> a >> b;
	try {
		c = div1(a, b);
	}
	catch (DivisionByZero) {
		cerr << "Error: Division by zero" << endl;
		return EXIT_FAILURE;
	}
	cout << c << endl;
	return EXIT_SUCCESS;
}