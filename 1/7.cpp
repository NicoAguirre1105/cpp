#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Payment
{
    string address;

    public:
    Payment (string add) : address(add) {}

    virtual double calc() = 0;
    virtual ~Payment() = default;
};

class Heat : public Payment
{
    double area;
    public:
    Heat(string add, double aa): Payment(add), area(aa) {}

    double calc()
    {
        return 50 * area;
    }
};

class Water : public Payment
{
    int people;
    public:
    Water(string add, int pp): Payment(add), people(pp) {}

    double calc()
    {
        return 200 * people;
    }
};
class Electricity : public Payment
{
    double kw_h;
    public:
    Electricity(string add, double aa): Payment(add), kw_h(aa) {}

    double calc()
    {
        return 5 * kw_h;
    }
};

int main ()
{
    Payment* arr[7];
	Heat* H1 = new Heat("A", 40);
	Heat* H2 = new Heat("B", 60);
	Water* W1 = new Water("AA", 1);
	Water* W2 = new Water("BB", 2);
	Water* W3 = new Water("CC", 3);
	Electricity* E1 = new Electricity("AAA", 55.4);
	Electricity* E2 = new Electricity("BBB", 33);
	arr[0] = H1;
	arr[1] = H2;
	arr[2] = W1;
	arr[3] = W2;
	arr[4] = W3;
	arr[5] = E1;
	arr[6] = E2;
	
	double count = 0;
	double curr;
	for (int i = 0; i < 7; i++) {
		curr = arr[i]->calc();
		cout << "Payment number " << i+1 << ": " << curr << endl;
		count += curr;
        delete arr[i];
	}
	cout << "Total: " << count << endl;

    return EXIT_SUCCESS;
}