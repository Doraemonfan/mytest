//
// zShellSort.hpp
// 2018/4/30
// zLimbo
//

#ifndef __Z_SHELLSORT_HPP__
#define __Z_SHELLSORT_HPP__

#include <vector>

namespace zLimbo {

using std::vector;

template <typename T>
void zShellSort(vector<T>& v, int lo, int hi) {
	int range = 1;
	while (range * 3 < hi - lo) 
		range = range * 3 + 1; // 1,4,13,40,...
	while (range >= 1) {
		for (long i = lo + range; i < hi; ++i) {
			long j = i - range;
			T tmpE = v[i];
			while (j >= lo && tmpE < v[j]) {
				v[j+range] = v[j];
				j -= range;
			}
			v[j+range] = tmpE;
		}
		range /= 3;
	}
}

template <typename T>
void zShellSort(vector<T>& v) {
	zShellSort(v, 0, v.size());
}


}; // namespace zLimbo

#endif // zShellSort.hpp

	
