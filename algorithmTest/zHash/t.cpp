#include <iostream>
#include <cstdlib>

using namespace std;

class Entry {

public:
	Entry(int k = -1, int v = 0):
		_key(k), _value(v)
	{ }
	int _key;
	int _value;
};

class Hash {

public:
	Hash(int sz): _sz(sz) {
		_h = new Entry[sz];
		if (!_h)
			abort();
	}
	~Hash() { delete[] _h; }
	int& operator[](int k) {
		return _h[k % _sz];
	}
	int insert(int v) {


private:
	int _sz;
	Entry* _h;
};

int main() {
	Hash ha(100);

	return 0;
}
