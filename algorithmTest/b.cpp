#include <vector>
#include <iostream>
#include "zHeapSort.hpp"

using namespace std;
using namespace zLimbo;

template <typename T>
void tsort(vector<T>& v) {
	zMaxHeap<T> zh(v);
	zh.build();
	long ic = v.size();
	while (!zh.empty()) {
		cout << "* " << zh.size() << "* ";
		v[--ic] = zh.pop();
	}
}

int main() {
	vector<long> vl;
	for (int i = 120;  i >= 0; --i) {
		vl.push_back(i);
	}
	cout << "################################" << endl;
	for (long i : vl) cout << i << " ";
	cout << "\n#############################" << endl;
	cout << "size:" << vl.size() << endl;

	zHeapSort(vl);

	cout << "################################" << endl;
	for (long i : vl) cout << i << " ";
	cout << "\n#############################" << endl;
	cout << "size:" << vl.size() << endl;

	return 0;
}

