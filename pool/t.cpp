//
// main.cpp
// pool
// 2018/5/21
// zlimbo
//

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>

#include "StackAlloc.hpp"
//#include "MemoryPool.hpp"

using namespace std; 

constexpr long ELEMS = 25000000;
constexpr int REPS = 50; 

int main() {
	clock_t start;
	StackAlloc<int, allocator<int>> stackDefault;
	start = clock();
	for (int j = 0; j < REPS; ++j) {
		assert(stackDefault.empty());
		for (int i = 0; i < ELEMS; ++i)
			stackDefault.push(i);
		for (int i = 0; i < ELEMS; ++i)
			stackDefault.pop();
	}
	cout << "Default Allocator Time: ";
	cout << ((static_cast<double>(clock()) - start) / 
			CLOCKS_PER_SEC) << "\n\n";

	return 0;
}
	
