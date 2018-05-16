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
	cout << endl;
	tree.show();
	cout << '\n';
	tree.show1();
	cout << '\n';
	Tree<string> Stree;
	Stree.insert("I am child!");
	Stree.insert("You are a boy.");
	Stree.insert("She is bad.");
	Stree.insert("He is cute.");
	Stree.show();
	Stree.clear();
	Stree.show();
	return 0;
}

