//
// zHeapSort.hpp
// 2018/5/5
// zLimbo
//

#ifndef _Z_HEAP_SORT_HPP
#define _Z_HEAR_SORT_HPP

#include <vector>
#include <cstdlib>

#include <cstdio>
using namespace std;

namespace zLimbo {
	
using std::vector;

template <typename T>
class zMaxHeap {

public:
	zMaxHeap(vector<T>& v):
		_v(v), _size(v.size()), isBuild(false) 
	{ }
	void build();
	void push(const T& e);
	T pop();
	T top() const { return _v[0]; }
	long size() const { return _size; }
	bool empty() const { return !_size; }
private:
	void upFilter(long r);
	void downFilter(long r);
	long maxThree(long ret);
	vector<T>& _v;
	long _size;
	bool isBuild;
};


template <typename T>
void zMaxHeap<T>::downFilter(long r) {
	T cmpE = _v[r];
	long ex;

	auto maxThree = [&](long pa)->long {
		long lc = (pa<<1) + 1;
		long rc = (pa<<1) + 2;
		if (rc < _size && _v[rc] > cmpE 
				&& _v[rc] > _v[lc]) 
			return rc;
		else if(lc < _size && _v[lc] > cmpE) 
			return lc;
		else
			return pa;
	};

	while (r != ( ex=maxThree(r) )) {
		_v[r] = _v[ex];
		r = ex;
	}
	_v[r] = cmpE;
}

template <typename T>
void zMaxHeap<T>::upFilter(long r) {
	T cmpE = _v[r];
	long ex;
	while (r > 0 && cmpE > _v[ex=(r-1)>>1]) {
		_v[r] = _v[ex];
		r = ex;
	}
	_v[r] = cmpE;
}

template <typename T>
void zMaxHeap<T>::build() {
	long mi = (_size - 1) >> 1;
	while (mi >= 0) {
		downFilter(mi);		
		--mi;
	}
}
	
template <typename T>
void zMaxHeap<T>::push(const T& e) {
	if (_v.size() <= _size)
		_v.resize(_size+1);
	_v[_size] = e;
	++_size;
	upFilter(_size-1);
}

template <typename T>
T zMaxHeap<T>::pop() {
	if (_size <= 0) abort();
	T retE = _v[0];	
	_v[0] = _v[_size-1];
	--_size;
	downFilter(0);
	return retE;
}

template <typename T>
void zHeapSort(vector<T>& v) {
	zMaxHeap<T> zh(v);
	zh.build();
	long ic = v.size();
	while (!zh.empty()) 
		v[--ic] = zh.pop();
}
	
}; // namespace zLimbo

#endif // zHeapSort.hpp

	
	
