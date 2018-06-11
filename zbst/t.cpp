#include <iostream>
#include "zbst.hpp"

using namespace std;
using namespace zlimbo;

int main() {
	Tree<int> tree;
	default_random_engine e(time(0));
	uniform_int_distribution<int> u(-9, 9);
	cout << "\ninput: ";
	for (int i = 0; i < 20; ++i) {
		int t = u(e);
		cout << t << " ";
		tree.insert(t);
	}

	tree.insert(0);
	tree.insert(-2);
	tree.insert(4);
	tree.insert(2);
	tree.insert(3);
	tree.insert(-1);
	cout << endl;
	tree.show();
	cout << '\n';
	tree.travelLevel();
	cout << '\n';
	tree.travelPre();
	cout << "\n";
	tree.travelMedi();
	cout << "\n";
	tree.travelPost();
	cout << "\n";
	return 0;
}

