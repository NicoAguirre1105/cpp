#include <iostream>
#include <cstdlib>
using namespace std;

struct Integer;
struct Real;
struct Complex;

struct Number
{
	virtual ~Number() = default;
	virtual Number &operator+(const Number&) const = 0;
	virtual Number &operator+(const Integer&) const = 0;
	virtual Number &operator+(const Real&) const = 0;
	virtual Number &operator+(const Complex&) const = 0;
};

struct Integer : Number
{
	int n;
	Number &operator+(const Number&) const;
	Number &operator+(const Integer&) const;
	Number &operator+(const Real&) const;
	Number &operator+(const Complex&) const;
};

struct Real : Number
{
	double a;
	Number &operator+(const Number&) const;
	Number &operator+(const Integer&) const;
	Number &operator+(const Real&) const;
	Number &operator+(const Complex&) const;

};

struct Complex : Number
{
	double r, i;
	Number &operator+(const Number&) const;
	Number &operator+(const Integer&) const;
	Number &operator+(const Real&) const;
	Number &operator+(const Complex&) const;
};

Number &Integer::operator+(const Number &x) const{
	return x + *this;
}

Number &Integer::operator+(const Integer &x) const {
	Integer *res = new Integer;
	res->n = n + x.n;
	return *res;
}

Number &Integer::operator+(const Real &x) const {
	Real *res = new Real;
	res->a = n + x.a; 
	return *res;
}

Number &Integer::operator+(const Complex &x) const {
	Complex *res = new Complex;
	res->r = x.r + n;
	res->i = x.i;
	return *res;
}

Number &Real::operator+(const Number &x) const {
	return x + *this;
}

Number &Real::operator+(const Integer &x) const {
	Real *res = new Real;
	res->a = a + x.n;
	return *res;
	
}

Number &Real::operator+(const Real &x) const {
	Real *res = new Real;
	res->a = a + x.a;
	return *res;
}

Number &Real::operator+(const Complex &x) const {
	Complex *res = new Complex;
	res->r = a + x.r;
	res->i = x.i;
	return *res;
}

Number &Complex::operator+(const Number &x) const {
	return x + *this;
}

Number &Complex::operator+(const Integer &x) const {
	Complex *res = new Complex;
	res->r = r + x.n;
	res->i = i;
	return *res;

}

Number &Complex::operator+(const Real &x) const {
	Complex *res = new Complex;
	res->r = r + x.a;
	res->i = i;
	return *res;
}

Number &Complex::operator+(const Complex &x) const {
	Complex *res = new Complex;
	res->r = r + x.r;
	res->i = i + x.i;
	return *res;
}

int main()
{
	Integer x; x.n = 1;
	Real y; y.a = 5.5;
	Number &p = x,  &q = y;
	Number &z = x + y;
	Real *r = (Real *) (&z);

	cout << r->a << endl;
        
	return EXIT_SUCCESS;
}

// bool Cell::operator<(const Cell& x) const {
// 	if (typeid(*cell) != typeid(*x.cell)) {
// 		return typeid(*cell).before(typeid(*x.cell));
// 	}
// 	if (typeid(*cell) == typeid(Integer)) {
// 		return ((Integer*)cell)->n < ((Integer*)x.cell)->n;
// 	}
// 	else if (typeid(*cell) == typeid(String)) {
// 		return ((String*)cell)->s < ((String*)x.cell)->s;
// 	}
// 	else if (typeid(*cell) == typeid(Array)) {
// 		return ((Array*)cell)->arr < ((Array*)x.cell)->arr;
// 	}
// 	else if (typeid(*cell) == typeid(As_Array)) {
// 		return ((As_Array*)cell)->as_arr < ((As_Array*)x.cell)->as_arr;
// 	}
// }
// bool Cell::operator>(const Cell& x) const {
// 	return x < *this;
// }