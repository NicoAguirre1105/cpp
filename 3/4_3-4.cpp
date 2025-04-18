#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

struct NoFile1 {};
struct File2Exists {};

void copy_f(string inf, string outf) {
	if (!std::filesystem::exists(inf)) throw NoFile1();
	if (std::filesystem::exists(outf)) throw File2Exists();

	ifstream source;
	ofstream target;
	source.open(inf, ios::binary);
	target.open(outf, ios::binary);
	target << source.rdbuf();
}

int main()
{
	string s1, s2;
    cout << "Enter the name of the source file and the name of the target file: ";
	cin >> s1 >> s2;
	bool success = false;
	while (!success) {
		try {
			copy_f(s1, s2);
			success = true;
		}
		catch (NoFile1) {
			cerr << "ERROR: Source file does not exist" << endl << "Please enter source name again" << endl;
			cin >> s1;
		}
		catch (File2Exists) {
			cerr << "ERROR: Target file already exists" << endl << "Please enter target name again" << endl;
			cin >> s2;
		}
	}
	return EXIT_SUCCESS;
}