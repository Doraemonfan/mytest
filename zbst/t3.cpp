#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
class zTnode {

public:
	zTnode(const T& e, 
		zTnode* pa = nullptr,
		zTnode* lc = nullptr, 
		zTnode* rc = nullptr):
		_e(e), _pa(pa), _lc(lc), _rc(rc)
	{ }
	T _e;
	zTnode* _pa;
	zTnode* _lc;
	zTnode* _rc;
};

template <typename T>
class zTree {
	
public:
	zTree(): _root(nullptr), _size(0) { }
	zTree(const T& e) {
		_root = new zTnode<T>(e);
		_size = 1;
	}
	~zTree() { dropChTree(_root); }
	void clear() { dropChTree(_root); }
	zTnode<T>* insert(const T& e);
//	void show() const;
//private:
	void dropChTree(zTnode<T>*& ch);
	zTnode<T>* _root;
	int _size;
};

template <typename T>
void zTree<T>::dropChTree(zTnode<T>*& np) {
	if (!np) return;
	dropChTree(np->_lc);
	dropChTree(np->_rc);
	delete np;
	np = nullptr;
}

template <typename T>
zTnode<T>* zTree<T>::insert(const T& e) {
	zTnode<T>* np = _root;
	zTnode<T>* hot = nullptr;
	while (np) {
		hot = np;
		if (e < np->_e) np = np->_lc;
		else if (e > np->_e) np = np->_rc;
		else return np;
	}
	np = new zTnode<T>(e, hot);
	if (!hot) _root = np;
	else if (e < hot->_e) hot->_lc = np;
	else hot->_rc = np;
	++_size;
	return np;
}

template <typename T>
void zTree::show() const {
	zTnode<T>* np = _root;
	int nl = 0;
	

int main() {
	zTree<int> zt(4);
	cout << zt._root->_e << endl;
	zTnode<int>* p2 = zt.insert(3);
	cout << zt._root->_e << endl;
	cout << zt._root << endl;
	cout << zt._root->_lc->_e << endl;
	cout << p2 << endl;
	cout << p2->_e << endl;
	cout << p2->_pa->_e << endl;
	zt.clear();
	cout << zt._root << endl;
	return 0;
}

