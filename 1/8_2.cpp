#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Expr {
    public:
	Expr() {}

	virtual void print() = 0;
	virtual double eval(double x) = 0;
	virtual Expr* der() = 0;
	virtual Expr* clone() = 0;
	virtual ~Expr() {}
};

class Constant : public Expr {
	double value;
    public:
	Constant(double vv) : value(vv) {}

	void print() 
    { 
        cout << value; 
    }
    
	double eval(double x) 
    { 
        return value; 
    }
	
    Expr *der() {
		Expr *ans = new Constant(0);
		return ans;
	}

	Expr *clone() {
		Expr *ans = new Constant(value);
		return ans;
	}
};

class Variable : public Expr {
    public:
	Variable() {}

	void print() 
    { 
        cout << "x"; 
    }

	double eval(double x)
    { 
        return x; 
    }

	Expr *der() {
		Expr *ans = new Constant(1);
		return ans;
	}

	Expr *clone() {
		Expr *ans = new Variable();
		return ans;
	}
};

class Sum : public Expr {
	Expr *left, *right;
    public:
	Sum(Expr *ll, Expr *rr): left(ll), right(rr){}
    
	void print() {
		cout << "(";
		left->print();
		cout << " + ";
		right->print();
		cout << ")";
	}

	double eval(double x) {
		double aux1 = left->eval(x);
		double aux2 = right->eval(x);
		return aux1 + aux2;
	}
	Expr *der() {
		Expr *ans = new Sum(left->der(), right->der());
		return ans;
	}
	Expr *clone() {
		Expr *ans = new Sum(left->clone(), right->clone());
		return ans;
	}

    ~Sum()
    {
        delete left;
        delete right;
    }
};

class Mult: public Expr {
	Expr *left, *right;
    public:
	Mult(Expr *ll, Expr *rr): left(ll), right(rr) {}

	void print() { 
		left->print();
		cout << " * ";
		right->print();
	}

	double eval(double x) { 
		double aux1 = left->eval(x);
		double aux2 = right->eval(x);
		return aux1 * aux2;
	}

	Expr *der() {
		Expr *ans = new Sum(new Mult(left->der(), right->clone()), new Mult(left->clone(), right->der()));
		return ans;
	}

	Expr *clone() {
		Expr *ans = new Mult(left->clone(), right->clone());
		return ans;
	}

    ~Mult()
    {
        delete left;
        delete right;
    }
};

class Sin : public Expr {
	Expr *exp;
    public:
	Sin(Expr *ee) : exp(ee) {}

	void print() {
		cout << "sin(";
		exp->print();
		cout << ")";
	}
	double eval(double x) {
		double r = exp->eval(x);
		return sin(r);
	}
    
	Expr *der();

	Expr *clone() {
		Expr *ans = new Sin(exp->clone());
		return ans;
	}

    ~Sin()
    {
        delete exp;
    }
};

class Cos : public Expr {
	Expr *exp;
    public:
	Cos(Expr *ee) : exp(ee) {}

	void print() {
		cout << "cos(";
		exp->print();
		cout << ")";
	}

	double eval(double x) { 
		double r = exp->eval(x);
		return cos(r); 
	}

	Expr *der() {
		Expr *ans = new Mult(new Mult(new Constant(-1), new Sin(exp->clone())), exp->der());
		return ans;
	}
	Expr *clone() {
		Expr *ans = new Cos(exp->clone());
		return ans;
	}

    ~Cos()
    {
        delete exp;
    }
};

Expr *Sin::der() {
	Expr *ans = new Mult(new Cos(exp->clone()), exp->der());
	return ans;
}

int main()
{
	Expr *A = new Sum(new Cos(new Mult(new Constant(M_PI), new Variable())), new Variable());
	Expr *B = new Sum(new Constant(7), new Sin(new Variable()));
	Expr *C = new Mult(A, B);
	C->print();
	cout << endl;
	cout << C->eval(1);

    delete C;
	
	return EXIT_SUCCESS;
    
}