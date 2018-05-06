//
// zQuickSort.hpp 
// 2018/5/1
// zLimbo
//

#ifndef __Z_QUICK_SORT_HPP__
#define __Z_QUICK_SORT_HPP__

#include <vector>
#include <random>
#include "zSwap.hpp"

namespace zLimbo {

	using namespace std;
	
static long zCutPoint(long lo, long hi) {
	uniform_int_distribution<long> u(lo, hi-1);
	static default_random_engine e(clock());
	return u(e);
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
	long p = zCutPoint(lo, hi);
	zSwap(v[lo], v[p]);
	p = zPartition(v, lo, hi);

//	cout << "# " << v[p] << " " << lo << " " << hi << " #";
//	for (long i = lo; i < hi; ++i) cout << v[i] << " ";
//	cout << endl;

	zQuickSort(v, lo, p);
	zQuickSort(v, p + 1, hi);
}
	
template <typename T>
void zQuickSort(vector<T>& v) {
	zQuickSort(v, 0, v.size());
}

template <typename T>
long zPartition2(vector<T>& v, long lo, long hi) {
	T cmpE = v[lo];
	long lu = lo, vi = lo;
	while (++vi < hi) 
		if (v[vi] < cmpE) 
			zSwap(v[++lu], v[vi]);
	zSwap(v[lo], v[lu]);
	return lu;
}
	
template <typename T>
void zQuickSort2(vector<T>& v, long lo, long hi) {
	if (hi - lo <= 1) return;
	long p = zCutPoint(lo, hi);
	zSwap(v[lo], v[p]);
	p = zPartition2(v, lo, hi);

//	cout << "# " << v[p] << " " << lo << " " << hi << " #";
//	for (long i = lo; i < hi; ++i) cout << v[i] << " ";
//	cout << endl;

	zQuickSort2(v, lo, p);
	zQuickSort2(v, p + 1, hi);
}
	
template <typename T>
void zQuickSort2(vector<T>& v) {
	zQuickSort2(v, 0, v.size());
}


}; // namespace zLimbo

#endif // zQuickSort.hpp
			


