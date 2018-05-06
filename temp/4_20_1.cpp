 #include <iostream>

using namespace std;

class A {

public:
	virtual ~A() = 0;
};

A::~A() { }

class B : public A {

};


int main() {
	B a;
	B b(a);
	B c;

	return 0;
}
