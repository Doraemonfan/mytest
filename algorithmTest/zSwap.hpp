//
// zSwap.hpp
// 2018/4/29
// zLimbo
//

#ifndef __Z_SWAP_H__
#define __Z_SWAP_H__

#include <utility>

namespace zLimbo {

template <typename T>
void zSwap(T& lhs, T& rhs) {
	if (lhs != rhs) {
		T tmp = lhs;
		lhs = rhs;
		rhs = tmp;
	}
}

}; // namespace zLimbo

#endif // zSwap.hpp

/*///////////////////////////////////
template <typename T>
void zSwap(T& lhs, T& rhs) {
	T tmp = std::move(lhs);
	lhs = std::move(rhs);
	rhs = std::move(tmp);
}
void zSwap(int lhs, int rhs) {
	if (lhs != rhs) {
		lhs = lhs ^ rhs;
		rhs = rhs ^ lhs;
		lhs = rhs ^ lhs;
	}
}
*/////////////////////////////////
