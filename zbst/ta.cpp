#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ostringstream sout;
	sout << "hellow, world";
	string s = sout.str();
	cout << s.size() << endl;
	cout << sout.str() << endl;

	return 0;
}
