#include <iostream>
#include <cstdlib>

using namespace std;

class Expression {
    public:
	Expression() {};

	virtual double evaluate() = 0;
    virtual ~Expression() = default;
};

class Number : public Expression {
	double value;
    public:
	Number(double x) : value(x) {};

	double evaluate() 
    { 
        return value; 
    }
};

class BinaryOperation : public Expression {
	Expression *left, *right;
	char oper;
    public:
	BinaryOperation(Expression* ll, char oo, Expression* rr): left(ll), right(rr), oper(oo) {}

	double evaluate() {
		double x = left->evaluate();
		double y = right->evaluate();
		if (oper == '+') return x + y;
		if (oper == '-') return x - y;
		if (oper == '*') return x * y;
		if (oper == '/') return x / y;
	}

    ~BinaryOperation()
    {
        delete left;
        delete right;
    }
};

int main()
{ 
	Expression *A = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression *B = new BinaryOperation(new Number(3), '+', A);
	cout << A->evaluate() << endl;
	cout << B->evaluate() << endl;

    delete B;

	return EXIT_SUCCESS;
}