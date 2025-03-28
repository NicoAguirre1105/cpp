#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
using namespace std;

struct Foo {
	static int count;
	int id;
	Foo() {
		id = count++;
		cout << "Creating id " << id << endl;
	}
	~Foo() {
		cout << "Deleting id " << id << endl;
	}
};

int Foo::count = 0;

Foo glob;
Foo glob_ar[3];

int main()
{
	static Foo stat;
	static Foo stat_ar[2];
	Foo loc;
	Foo loc_ar_1[2];

	//2

	cout << endl << "Throwing before init" << endl;
	try {
		throw "error before init"s;
		Foo loc_ar_2[5];
		Foo* dyn_ar_2 = new Foo[5];
	}
	catch (string msg) {
		cerr << "In catch: " << msg << endl;
	}

	//in catch all its deleted
	cout << endl << "Throwing before dynamic init" << endl;
	try {
		Foo loc_ar_3[5];
		throw "after local, before dynamic"s;
		Foo* dyn_ar_3 = new Foo[5];
	}
	catch (string msg) {
		cerr << "In catch: " << msg << endl;
	}

	cout << endl << "Throwing after init" << endl;
	try {
		Foo loc_ar_4[5];
		Foo* dyn_ar_4 = new Foo[5];
		throw "after init"s;
	}
	catch (string msg) {
		cerr << "In catch: " << msg << endl;
	}

	//3 - unique_ptr
	cout << endl << "Throwing after init with unique_ptr" << endl;
	try {
		throw "after init with unique_ptr"s;
		Foo loc_ar_5[5];
		unique_ptr<Foo[]> dyn_ar_5(new Foo[5]);
	}
	catch (string msg) {
		cerr << "In catch: " << msg << endl;
	}
	
	cout << endl;
	return EXIT_SUCCESS;
}