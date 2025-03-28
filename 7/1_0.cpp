#include <iostream>
#include <cstdlib>
#include <string>
#include <omp.h>
#include <cmath>
#include <ctime>	
using namespace std;
const double PI = 3.141592653589793238463;
int n = 100000000;
double* sins = new double[n];
double* sins_par = new double[n];


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Sequence" << endl;
	clock_t t = clock();
	for (int i = 0; i < n; i++) {
		sins[i] = sin(i * PI / 2 / n);
	}
	cout << "Time: " << omp_get_wtime() - t << endl;

	cout << "4 Веток" << endl;
	clock_t t1 = clock();
#pragma omp parallel sections
	{
#pragma omp section 
		{
			for (int i = 0; i < n / 12; i++) {
				sins_par[i] = sin(i * PI / 2 / n);
			}
		}
#pragma omp section 
		{
			for (int i = n / 12; i < 2 * n / 12; i++) {
				sins_par[i] = sin(i * PI / 2 / n);
			}
		}
#pragma omp section 
		{
			for (int i = 2 * n / 12; i < 3 * n / 12; i++) {
				sins_par[i] = sin(i * PI / 2 / n);
			}
		}
#pragma omp section 
		{
			for (int i = 3 * n / 12; i < 4 * n / 12; i++) {
				sins_par[i] = sin(i * PI / 2 / n);
			}
		}
		clock_t t2 = clock();
	cout << "Time1: " << (double(t - t1)/CLOCKS_PER_SEC) << endl;
	cout << "Time2: " << (double(t1 - t2)/CLOCKS_PER_SEC) << endl;

	return EXIT_SUCCESS;
}
}