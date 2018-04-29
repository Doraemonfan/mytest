#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int main() {

	default_random_engine e(time(0) * time(0));	
	for (int i = 0; i < 10; ++i) {
		cout << e() << endl;
	}
	return 0;
}
