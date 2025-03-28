#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
using namespace std;

struct Foo {
	static int count;
	int id;
	Foo() {
		id = ++count;
		if (id == 7) throw "Id = 7"s;
		if (id == 14) throw "Id = 14"s;
		cout << "Creating id " << id << endl;

	}
	~Foo() {
		cout << "Deleting id " << id << endl;
	}
};

int Foo::count = 0;

struct Bar {
	Foo* ar;
	Bar(): ar(new Foo[10]) {
		cout << "Creating Bar" << endl;
	}
	~Bar() {
		cout << "Deleting Bar" << endl;
		delete[] ar;
	}
};

struct Bar_un {
	unique_ptr<Foo[]> ar;
	Bar_un() : ar(new Foo[10]) {
		cout << "Creating Bar_un" << endl;
	}
	~Bar_un() {
		cout << "Deleting Bar_un" << endl;
	}
};

int main()
{
	try {
		Bar a;
	}
	catch (string msg) {
		cerr << "Error: " << msg << endl;
	}
	try {
		Bar_un b;
	}
	catch (string msg) {
		cerr << "Error: " << msg << endl;
	}
	return EXIT_SUCCESS;
}