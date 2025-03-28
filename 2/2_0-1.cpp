#include <iostream>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

struct Integer;
struct String;
struct Array;
struct As_Array;
struct Cell;

struct Cell
{
    Base *cell;

    ~Cell()
    {
        delete cell;
    }

    bool operator<(const Cell &x) const
    {
        return *cell < *(x.cell);
    }

    bool operator>(const Cell &x) const
    {
        return *cell > *(x.cell);
    }
};

struct Base
{
    virtual ~Base() = default;
	virtual bool operator>(const Base&) const = 0;
	virtual bool operator<(const Base&) const = 0;
	virtual bool operator>(const Integer&) const = 0;
	virtual bool operator<(const Integer&) const = 0;
	virtual bool operator>(const String&) const = 0;
	virtual bool operator<(const String&) const = 0;
	virtual bool operator>(const Array&) const = 0;
	virtual bool operator<(const Array&) const = 0;
	virtual bool operator>(const As_Array&) const = 0;
	virtual bool operator<(const As_Array&) const = 0;
};

struct Integer : Base
{
    int n;
    bool operator>(const Base&) const;
    bool operator<(const Base&) const;
    bool operator>(const Integer&) const;
    bool operator<(const Integer&) const;
    bool operator>(const String&) const;
    bool operator<(const String&) const;
    bool operator>(const Array&) const;
    bool operator<(const Array&) const;
    bool operator>(const As_Array&) const;
    bool operator<(const As_Array&) const;
};

struct String : Base
{
    string s;
    bool operator>(const Base&) const;
    bool operator<(const Base&) const;
    bool operator>(const Integer&) const;
    bool operator<(const Integer&) const;
    bool operator>(const String&) const;
    bool operator<(const String&) const;
    bool operator>(const Array&) const;
    bool operator<(const Array&) const;
    bool operator>(const As_Array&) const;
    bool operator<(const As_Array&) const;
};

struct Array : Base
{
    vector<Cell> arr;
    bool operator>(const Base&) const;
    bool operator<(const Base&) const;
    bool operator>(const Integer&) const;
    bool operator<(const Integer&) const;
    bool operator>(const String&) const;
    bool operator<(const String&) const;
    bool operator>(const Array&) const;
    bool operator<(const Array&) const;
    bool operator>(const As_Array&) const;
    bool operator<(const As_Array&) const;
};

struct As_Array : Base
{
    map<string, Cell> as_arr;
    bool operator>(const Base&) const;
    bool operator<(const Base&) const;
    bool operator>(const Integer&) const;
    bool operator<(const Integer&) const;
    bool operator>(const String&) const;
    bool operator<(const String&) const;
    bool operator>(const Array&) const;
    bool operator<(const Array&) const;
    bool operator>(const As_Array&) const;
    bool operator<(const As_Array&) const;
};

// < Base

bool Integer::operator<(const Base &x) const
{
    return x > *this;
}

bool String::operator<(const Base &x) const
{
    return x > *this;
}

bool Array::operator<(const Base &x) const
{
    return x > *this;
}

bool As_Array::operator<(const Base &x) const
{
    return x > *this;
}

// > Base

bool Integer::operator>(const Base &x) const
{
    return x < *this;
}

bool String::operator>(const Base &x) const
{
    return x < *this;
}

bool Array::operator>(const Base &x) const
{
    return x < *this;
}

bool As_Array::operator>(const Base &x) const
{
    return x < *this;
}

// < Integer

bool Integer::operator<(const Integer &x) const
{
    return n < x.n;
}

bool String::operator<(const Integer &x) const
{
    return 0;
}

bool Array::operator<(const Integer &x) const
{
    return 0;
}

bool As_Array::operator<(const Integer &x) const
{
    return 0;
}

// > Integer

bool Integer::operator>(const Integer &x) const
{
    return n > x.n;
}

bool String::operator>(const Integer &x) const
{
    return 1;
}

bool Array::operator>(const Integer &x) const
{
    return 1;
}

bool As_Array::operator>(const Integer &x) const
{
    return 1;
}

// < String

bool Integer::operator<(const String &x) const
{
    return 1;
}

bool String::operator<(const String &x) const
{
    return s < x.s;
}

bool Array::operator<(const String &x) const
{
    return 0;
}

bool As_Array::operator<(const String &x) const
{
    return 0;
}

// > String

bool Integer::operator>(const String &x) const
{
    return 0;
}

bool String::operator>(const String &x) const
{
    return s > x.s;
}

bool Array::operator>(const String &x) const
{
    return 1;
}

bool As_Array::operator>(const String &x) const
{
    return 1;
}

// < Array

bool Integer::operator<(const Array &x) const
{
    return 1;
}

bool String::operator<(const Array &x) const
{
    return 1;
}

bool Array::operator<(const Array &x) const
{
    return arr < x.arr;
}

bool As_Array::operator<(const Array &x) const
{
    return 0;
}

// > Array

bool Integer::operator>(const Array &x) const
{
    return 0;
}

bool String::operator>(const Array &x) const
{
    return 0;
}

bool Array::operator>(const Array &x) const
{
    return arr > x.arr;
}

bool As_Array::operator>(const Array &x) const
{
    return 1;
}

// < As_Array

bool Integer::operator<(const As_Array &x) const
{
    return 1;
}

bool String::operator<(const As_Array &x) const
{
    return 1;
}

bool Array::operator<(const As_Array &x) const
{
    return 1;
}

bool As_Array::operator<(const As_Array &x) const
{
    return as_arr < x.as_arr;
}

// > As_Array

bool Integer::operator>(const As_Array &x) const
{
    return 0;
}

bool String::operator>(const As_Array &x) const
{
    return 0;
}

bool Array::operator>(const As_Array &x) const
{
    return 0;
}

bool As_Array::operator>(const As_Array &x) const
{
    return as_arr > x.as_arr;
}

int main()
{
    return EXIT_SUCCESS;
}
