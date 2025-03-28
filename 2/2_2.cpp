#include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <vector>
#include <map>
using namespace std;

struct Integer;
struct String;
struct Array;
struct As_Array;

struct Base
{
	virtual ~Base() {}
};

struct Cell {
	Base *cell;

	~Cell() 
    {
		delete cell;
	}

	bool operator<(const Cell& x) const;
	bool operator>(const Cell& x) const;
};

struct Integer : Base
{
	int n;
};

struct String : Base
{
	string s;
};

struct Array : Base
{
	vector<Cell> arr;
};

struct As_Array : Base
{
	map<string, Cell> as_arr;
};

int main()
{
	return EXIT_SUCCESS;
}