//
// zBubbleSort.hpp
// 2018/4/30
// zLimbo
// 

#ifndef __Z_BUBBLESORT_HPP__
#define __Z_BUBBLESORT_HPP__

#include <vector>

namespace zLimbo {
	using std::vector;

template <typename T>
void zBubbleSort(vector<T>& v) {
	long len = v.size();
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (long j = 1; j < len; ++j) {
			if (v[j-1] > v[j]) {
				zSwap(v[j-1], v[j]);
				isSorted = false;
			}
		}
		--len;
	}
}

}; // namespace zLimbo

#endif // zBubbleSort.hpp

