//
// zHeapSort.hpp
// 2018/5/5
// zLimbo
//

#ifndef _Z_HEAP_SORT_HPP
#define _Z_HEAR_SORT_HPP

#include <vector>

namespace zLimbo {
	
using namespace std;

template <typename T>
class zMinHeap {

public:
	zMinHeap(vector<T>& v):
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
	long minThree(long ret);
	vector<T>& _v;
	long _size;
	bool isBuild;
};

template <typename T>
inline long zMinHeap<T>::minThree(long ret) {
	long l = (ret<<1) + 1;
	long r = (ret<<1) + 2;
	if (l < _size && _v[l] < _v[ret]) ret = l;
	if (r < _size && _v[r] < _v[ret]) ret = r;
	return ret;
}

template <typename T>
void zMinHeap<T>::downFilter(long r) {
	T cmpE = _v[r];
	long ex;
	while (cmpE > _v[ex=minThree(r)]) {
		_v[r] = _v[ex];
		r = ex;
	}
	_v[r] = cmpE;
}

template <typename T>
void zMinHeap<T>::upFilter(long r) {
	T cmpE = _v[r];
	long ex;
	while (r > 0 && cmpE > _v[ex=(r-1)>>1]) {
		_v[r] = _v[ex];
		r = ex;
	}
	_v[r] = cmpE;
}

template <typename T>
void zMinHeap<T>::build() {
	long mi = (_size - 1) >> 1;
	while (mi >= 0) {
		downFilter(mi);		
		++mi;
	}
}
	
template <typename T>
void zMinHeap<T>::push(const T& e) {
	if (_v.size() <= _size)
		_v.resize(_size+1);
	_v[_size] = e;
	++_size;
	upFilter(_size-1);
}

template <typename T>
T zMinHeap<T>::pop() {
	T retE = _v[0];	
	_v[0] = _v[_size-1];
	--_size;
	downFilter(0);
	return retE;
}

template <typename T>
void zHeapSort(vector<T>& v) {
	zMinHeap<T> zh(v);
	zh.build();
	long ic =v.size();
	while (!zh.empty())
		v[--ic] = zh.pop();
}
	
}; // namespace zLimbo

#endif // zHeapSort.hpp

	
	
