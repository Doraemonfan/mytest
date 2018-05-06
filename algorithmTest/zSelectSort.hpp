//
// zSelectSort.hpp
// 2018/4/30
// zLimbo
//

#ifndef __Z_SELECTSORT_HPP__
#define __Z_SELECTSORT_HPP__

#include <vector>
#include "zSwap.hpp"

namespace zLimbo {
	using std::vector;
template <typename T>
void zSelectSort(vector<T> &V) {
	long len = V.size();
	long min_n;
	for (long i = 0; i != len-1; ++i) {
		min_n = i;
		for (long j = i + 1; j != len; ++j) {
			if (V[j] < V[min_n]) {
				min_n = j;
			}	
		}
		zSwap(V[i], V[min_n]);
	}
	
}

template <typename T>
void zSelectSort2(vector<T> &V) {
	for (auto it = V.begin(); it != V.end()-1; ++it) {
		auto min_t = it;
		for (auto jt = it + 1; 
				jt != V.end(); ++jt) {
			if (*jt < *min_t) 
				min_t = jt;
		}
		zSwap(*it, *min_t);
	}
}


}; // namespace zLimbo

#endif // zSelectSort.hpp

