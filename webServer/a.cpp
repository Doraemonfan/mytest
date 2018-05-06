#include <iostream>
#include <thread>

using namespace std;

void foo() {
	cout << "Hello World!" << endl;
}

int main() {
	thread t(foo);
	t.join();
}
