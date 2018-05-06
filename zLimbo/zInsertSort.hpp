//
// zInsertSort.hpp
// 2018/4/30
// zLimbo
//

#ifndef __Z_INSERTSORT_HPP__
#define __Z_INSERTSORT_HPP__

#include <vector>

namespace zLimbo {

using std::vector;

template <typename T>
void zInsertSort(vector<T>& v) {
	long len = v.size();
	for (long i = 1; i < len; ++i) {
		T tmpE = v[i];
		for (int j = i-1; j >= 0 && v[j] < tmpE; --j) {
			v[j] = v[j-1];
		}
		v[j+1] = v[i];
	}
}

template <typename T>
void zInsertSort2(vector<T>& v) {
	for (auto it = v.begin()+1; it != v.end(); ++it) {
		T tmpE = *it;
		for (auto jt = it - 1; jt != v.rend() 
				&& *jt < tmpE; --ij) {
			*ij = *(ij - 1);
		}
		*(ij + 1) = tmpE;
	}
}

}; // namespace zLimbo

#endif // zInsertSort.hpp
			

