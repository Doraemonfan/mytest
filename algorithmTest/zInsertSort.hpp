//
// zInsertSort.hpp
// 2018/4/30
// zLimbo
//

#ifndef __Z_INSERTSORT_HPP__
#define __Z_INSERTSORT_HPP__

#include <vector>
#include "zSwap.hpp"

namespace zLimbo {

using std::vector;

template <typename T>
void zInsertSort(vector<T>& v, int lo, int hi) {
	for (long i = lo+1; i < hi; ++i) {
		T tmpE = v[i];
		int j = i - 1;
		while (j >= lo && v[j] > tmpE) {
			v[j+1] = v[j];
			--j;
		}
		v[j+1] = tmpE;
	}
}

template <typename T>
void zInsertSort(vector<T>& v) {
	zInsertSort(v, 0, v.size());
}

template <typename T>
void zInsertSort2(vector<T>& v) {
	for (auto it = v.begin()+1; it != v.end(); ++it) {
		T tmpE = *it;
		auto jt = it;
		while (jt != v.begin() && *(jt-1) > tmpE) {
			*jt = *(jt - 1);
			--jt;
		}
		*jt = tmpE;
	}
}

template <typename T>
void zInsertSort3(vector<T>& v) {
	long len = v.size();
	for (long i = 1; i < len; ++i) {
		int j = i - 1;
		while (j >= 0 && v[j] > v[j+1]) {
			zSwap(v[j], v[j+1]);
			--j;
		}
	}
}

}; // namespace zLimbo

#endif // zInsertSort.hpp
			

