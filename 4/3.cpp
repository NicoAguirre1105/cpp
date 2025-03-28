#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

double g(double x) 
{ 
    return sin(x) * sin(x); 
} 
 
double rectangle_method(double a, double b, double (*f)(double)) 
{ 
    int n = 100; 
    double sum = 0; 
    for (int i = 1; i <= n; i++) 
        sum += f(a + (i - 0.5) * (b - a) / n); 
    return sum * (b - a) / n; 
}

int main()
{
	// cout << rectangle_method(0, 1, g) << endl;
	cout << rectangle_method(0, 1, [] (double x) {return sin(x)*sin(x);}) << endl;
	return EXIT_SUCCESS;
}