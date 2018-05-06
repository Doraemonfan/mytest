#include "test3.h"



Test3::Test3(const std::string &st): _s(st) { }

void Test3::print() {
	std::cout << "Hello " << _s <<  std::endl;
}
/*
Test3& tes3() {
	static Test3 tes3("zLimbo!");
	return tes3;
}
*/

Test3 tes3("zLimbo!");

