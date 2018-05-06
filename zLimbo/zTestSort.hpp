//
// zTestSort.hpp
// 2018/4/30
// zLimbo
//

#ifndef __Z_TESTSORT_H__
#define __Z_TESTSORT_H__

#include <vector>
#include <string>
#include <random>
#include <assert.h>
#include "zTimer.hpp"

namespace zLimbo {

	using namespace std;

void zTestInt( void (*sortFun)(vector<long> &), 
		const string& info = "",
		long F = 20, long N = 1000, long U = 1000) {

	uniform_int_distribution<long> u(0, U);
	default_random_engine e((unsigned)time(0));
	zTimer zt;
	
	vector<long> vInt;
	zt.start();
	zt.pause();
	for (long i = 0; i < F; ++i) {
		for (long j = 0; j < N; ++j) 
			vInt.push_back(u(e));

		zt.goOn();
		sortFun(vInt);
		zt.pause();

		for (long j = 1; j < N; ++j)
			assert(vInt[j-1] <= vInt[j]);
	}
	zt.end();
	zt.show(info, ".");
}

void zTestReal( void (*sortFun)(vector<double> &), 
		const string& info = "",
		long F = 20, long N = 1000, long U = 1) {

	uniform_real_distribution<double> u(0, U);
	default_random_engine e((unsigned)time(0));
	zTimer zt;
	
	vector<double> vReal;
	zt.start();
	zt.pause();
	for (long i = 0; i < F; ++i) {
		for (long j = 0; j < N; ++j) 
			vReal.push_back(u(e));

		zt.goOn();
		sortFun(vReal);
		zt.pause();

		for (long j = 1; j < N; ++j)
			assert(vReal[j-1] <= vReal[j]);
	}
	zt.end();
	zt.show(info, ".");
}

}; // namespace zLimbo

#endif // zTestSort.hpp
