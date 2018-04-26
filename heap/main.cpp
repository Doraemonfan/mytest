#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
class Heap {

private:
	shared_ptr<vector<T>> _hp;
	void filter_down(int);
	void filter_up(int);
	inline int LargeOfThree(int);
public:
	explicit Heap(const vector<T> &v);
	void push(const T &e);
	T top() const;
	T pop();
	void show() const;
};

template <typename T>
Heap<T>::Heap(const vector<T> &v):
	_hp(make_shared<vector<T>>(v))
{
	for (int i = (_hp->size()>>1)-1; i >= 0; --i)
		filter_down(i);
}

template <typename T>
inline int Heap<T>::LargeOfThree(int ret) {
	int lc = (ret<<1) + 1;
	int rc = (ret<<1) + 2;
	if (lc < _hp->size() && (*_hp)[ret] < (*_hp)[lc])
		ret = lc;
	if (rc < _hp->size() && (*_hp)[ret] < (*_hp)[rc])
		ret = rc;
	return ret;
}

template <typename T>
void Heap<T>::filter_down(int r) {
	if (r < 0 && r >= _hp->size()) return;
	T tmp = (*_hp)[r];
	int l = 0;
	while (r != (l = LargeOfThree(r))) {
		(*_hp)[r] = (*_hp)[l];
		r = l;
	}
	(*_hp)[r] = tmp;
}

template <typename T>
void Heap<T>::filter_up(int r) {
	if (r <= 0 && r >= _hp->size()) return;
	T tmp = (*_hp)[r];
	int l = (r-1) >> 1;
	while (l >= 0 && tmp > (*_hp)[l]) {
		(*_hp)[r] = (*_hp)[l];
		r = l;
		l = (r-1) >> 1;
	}
	(*_hp)[r] = tmp;
}

template <typename T>
void Heap<T>::push(const T &e) {
	_hp->push_back(e);
	filter_up(_hp->size()-1);
}

template <typename T>
T Heap<T>::top() const {
	if (_hp->empty()) 
		throw runtime_error("EMPTY HEAP!");
	return *( _hp->begin() );
}

template <typename T>
T Heap<T>::pop() {
	if (_hp->empty())
		throw runtime_error("EMPTY HEAP!");
	T tmp = *( _hp->begin() );
	*( _hp->begin() ) = *( _hp->end()-1 );
	_hp->resize(_hp->size()-1);
	filter_down(0);
	return tmp;
}	

template <typename T>
void Heap<T>::show() const {
	cout << "**************" << endl;
	cout << "size: " << _hp->size() << endl;
	for (auto &e : *_hp) cout << e << " ";
	cout << endl;
	cout << "\n*************" << endl;
}

void test() {
	vector<double> va;
	for (int i = 0; i < 20; ++i) {
		va.push_back(i/ 3.0);
	}

	Heap<double> ha(va);
	ha.show();
	ha.push(200);
	ha.show();
	ha.push(300);
	ha.show();
	ha.pop();
	ha.show();
}

int main() {
	test();

	return 0;
}
