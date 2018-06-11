#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class A {

};

template <typename T>
class B {

using Node = A<T>;

};

int main() {
	allocator<int> a;
	int *p = a.allocator(1);
	a.destroy(p);

	B<int> b;

	return 0;
}
