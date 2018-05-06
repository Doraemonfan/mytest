#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main() {
	ofstream fout("num.txt");
	uniform_int_distribution<unsigned> u(0, 100000);
	default_random_engine e;
	for (size_t i = 0; i != 100000; ++i)
		fout << u(e) << " ";
	return 0;
}
