#include <iostream>
#include "List.h"

using namespace std;

int main() {

	List<double> lsta;
	lsta.show();
	for (int i = 0; i < 20; ++i) 
		lsta.push_back(i / 3.0);
	for (int i = 50; i < 60; ++i)
		lsta.push_front(i / 3.0);
	lsta[2] = 100;
	lsta.insert(5, 300);
	lsta.show();
	lsta.erase(5);
	lsta.show();
	
	lsta.clear();
	lsta.show();

	return 0;
}
