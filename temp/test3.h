#include <iostream>
#include <string>

class Test3 {

private:
	std::string _s;
public:
	Test3(const std::string &st);
	void print();
};

//Test3& tes3();

extern Test3 tes3;

/*
Test3::Test3(const std::string &st): _s(st) { }

void Test3::print() {
	std::cout << "Hello " << _s <<  std::endl;
}

extern Test3 tes3("zLimbo!");
*/
