#include <iostream>
#include <vector>
#include <string>
#include "test3.h"
using namespace std;

class Test1 {

public:
	enum { Num2 = 10 };
	static const int Num = 5;
	int scores[Num];
	vector<int> vec[Num];
	int scores2[Num2];
	vector<double> vec2[Num2];
};

const int Test1::Num;

void test1() {
	Test1 tes;
	cout << "\n$ test1 $\n" << endl;
	cout << "Test1::Num=" << Test1::Num << endl;
	cout << "tes::Num=" << tes.Num << endl;
	cout << "Test1::Num2=" << Test1::Num2 << endl;
}

class Test2 {

private:
	string str;
	mutable int len;
	mutable char firstch;
	mutable string sums;
public:
	Test2(const string &s = ""): str(s) { }
	void parament() const {
		len = str.size();
		if (str.empty()) firstch = '\0';
		else firstch = str[0];
	}
	const string& add(const string& rhs) const {
		cout << "(const)" << endl;
		sums = str + rhs;
		return sums;
	}
	string& add(string& rhs) {
		cout << "(non-const)" << endl;
		return const_cast<string&>(
			add( static_cast<const string&>(rhs) ) );
	}
	void test3func() {
	//	tes3().print();
		tes3.print();
	}
};

void test2() {
	cout << "\n& test2 $\n";
	Test2 tes(string("zLimbo"));
	string s(" is a good boy!");
	const string s2(" isn't a good boy!");
	cout << "@ const @\n" << tes.add(s2) << endl;
	cout << "@ non-const @\n" <<  tes.add(s) << endl;
}

void test3() {
//	tes3().print();
	tes3.print();
	cout << "\n$ test3 $\n";
	Test2 tes;
	tes.test3func();
}

int main() {
	test1();
	test2();
	test3();
	return 0;
}
