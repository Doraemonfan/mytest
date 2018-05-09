#include <iostream>

using namespace std;

template <typename K, typename V>
class zEntry {

public:
	zHash(const K& k, const V& v): 
		_key(k), _value(v) 
	{ }


//private:
	K _key;
	V _value;
};


template <typename K, typename V>
class zHash {


private:
	zEntry<K,V> *_hash;
};

