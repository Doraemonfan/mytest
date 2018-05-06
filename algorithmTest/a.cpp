#include <iostream>
#include <random>
#include <ctime>
#include "zSwap.hpp"

using namespace std;
using namespace zLimbo;

static int Random(int lo, int hi) {
	uniform_int_distribution<int> u(lo, hi);
	static default_random_engine e(clock());
	return u(e);
}

int partition(vector<int>& a, int lo, int hi) {
	int i = lo, j = hi + 1;
	int v = a[lo];
	while (true) {
		while (a[++i] < v)
			if (i == hi) break;
		while (v < a[--j]) 
			if (j == lo) break;
		if (i >= j) break;
		std::swap(a[i], a[j]);
	}
	std::swap(a[lo], a[j]);
	return j;
}

void quickSort(vector<int>& a, int lo, int hi) {
	if (hi <= lo) return;
	int j = partition(a, lo, hi);

	cout << j << " | " << a[j] << " (" << lo << "," << hi << ") ";
	for (int i = lo; i <= hi; ++i) cout << a[i] << " ";
	cout << endl;

	quickSort(a, lo, j-1);
	quickSort(a, j+1, hi);
}

void quickSort(vector<int>& a) {
	quickSort(a, 0, a.size()-1);
}

template <typename T>
long zPartition(vector<T>& v, long lo, long hi) {
	T cmpE = v[lo];
	long li = lo + 1, ri = hi - 1;
	while (true) {
		while (li <= ri && v[li] <= cmpE) ++li;
		while (li <= ri && cmpE <= v[ri]) --ri;
		if (ri <= li) break;
		zSwap(v[li], v[ri]);
	}
	zSwap(v[lo], v[li-1]);
	return li - 1;
}
	
template <typename T>
void zQuickSort(vector<T>& v, long lo, long hi) {
	if (hi - lo <= 1) return;
	long p = zPartition(v, lo, hi);

	cout << "# " << v[p] << " " << lo << " " << hi << " #";
	for (long i = lo; i < hi; ++i) cout << v[i] << " ";
	cout << endl;

	zQuickSort(v, lo, p);
	zQuickSort(v, p + 1, hi);
}
	
template <typename T>
void zQuickSort(vector<T>& v) {
	zQuickSort(v, 0, v.size());
}
int main() {
	vector<int> a;
	a.push_back(20);
	for (int i = 0; i < 20; ++i)
		a.push_back(i);
	zQuickSort(a);
	for (int i : a) cout << i << " ";
	cout << endl;

	return 0;
}
