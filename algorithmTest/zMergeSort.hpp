//
// zMergeSort.hpp
// 2018/4/30
// zLimbo
//

#ifndef __Z_MERGESORT_HPP__
#define __Z_MERGESORT_HPP__

#include <vector>
#include "zInsertSort.hpp"
#include "zShellSort.hpp"

namespace zLimbo {


using std::vector;

template <typename T>
void zMerge(vector<T>& v, long b, 
		long m, long e, vector<T>& lv) {
	lv.resize(0);
	for (long i = b; i < m; ++i)
		lv.push_back(v[i]);
	vector<T>& rv = v;
	
	long li = 0, ri = m, vi = b;
	long lu = m - b, ru = e;
	while (li < lu && ri < ru) {
		if (rv[ri] < lv[li]) v[vi++] = rv[ri++];
		else v[vi++] = lv[li++];
	}
	while (li < lu) v[vi++] = lv[li++];
}

template <typename T>
void mergeSort(vector<T>& v, 
		long b, long e, vector<T>& lv) {
	
	if (e - b < 2) return;
	long m = (b + e) >> 1;
	mergeSort(v, b, m, lv);
	mergeSort(v, m, e, lv);
	zMerge(v, b, m, e, lv);
}

template <typename T>
void zMergeSort(vector<T>& v) {
	long len = v.size();
	vector<T> lv;
	lv.reserve(len >> 1 + 1);
	mergeSort(v, 0, len, lv);
}

template <typename T>
void zMergeSort2(vector<T>& v) {

	long len = v.size();
	vector<T> lv;
	lv.reserve((len >> 1) + 1);

	for (long sz = 1; sz < v.size(); sz <<= 1) {
		long b = 0;
		for (b = 0; b <= len-(sz<<1); b += (sz<<1)) 
			zMerge(v, b, b + sz, b + (sz<<1), lv);
		if (b <= len-sz)
			zMerge(v, b, b + sz, len, lv);
	}
}

template <typename T>
void mergeSort3(vector<T>& v, 
		long b, long e, vector<T>& lv) {
	if (e - b < 16) {
		zInsertSort(v, b, e);
		return;
	}
	long m = (b + e) >> 1;
	mergeSort3(v, b, m, lv);
	mergeSort3(v, m, e, lv);
	zMerge(v, b, m, e, lv);
}

template <typename T>
void zMergeSort3(vector<T>& v) {
	long len = v.size();
	vector<T> lv;
	lv.reserve(len >> 1 + 1);
	mergeSort3(v, 0, len, lv);
}

template <typename T>
void mergeSort4(vector<T>& v, 
		long b, long e, vector<T>& lv) {
	if (e - b < 10000) {
		zShellSort(v, b, e);
		return;
	}
	long m = (b + e) >> 1;
	mergeSort4(v, b, m, lv);
	mergeSort4(v, m, e, lv);
	zMerge(v, b, m, e, lv);
}

template <typename T>
void zMergeSort4(vector<T>& v) {
	long len = v.size();
	vector<T> lv;
	lv.reserve(len >> 1 + 1);
	mergeSort4(v, 0, len, lv);
}


}; // namespace zLimbo

#endif // zMergeSort.hpp
	
