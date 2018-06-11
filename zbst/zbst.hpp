//
// zbst.hpp 
// 2018/5/16
// zlimbo
//

#ifndef __Z_BST_HPP__
#define __Z_BST_HPP__

#include <iostream>
#include <random>
#include <stack>
#include <queue>
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace zlimbo {

template <typename T>
class Tnode {

public:
	Tnode(const T& e, 
		Tnode* pa = nullptr,
		Tnode* lc = nullptr, 
		Tnode* rc = nullptr):
		_e(e), _pa(pa), _lc(lc), _rc(rc)
	{ }
	T _e;
	Tnode* _pa;
	Tnode* _lc;
	Tnode* _rc;

	int _x;
	int _y;
	int _len;
};

template <typename T>
class Tree {
	
public:
	Tree(): _root(nullptr), _size(0) { }
	Tree(const T& e) {
		_root = new Tnode<T>(e);
		_size = 1;
	}
	~Tree() { dropChTree(_root); }
	void clear() { dropChTree(_root); }
	Tnode<T>* insert(const T &e);
	void show() const;
	void travelLevel();
	void travelPre();
	void travelMedi();
	void travelPost();
	Tnode<T>* search(const T &e);
private:
	void dropChTree(Tnode<T>*& ch);
	Tnode<T>* _root;
	int _size;
};

template <typename T>
void Tree<T>::dropChTree(Tnode<T>*& np) {
	if (!np) return;
	dropChTree(np->_lc);
	dropChTree(np->_rc);
	delete np;
	--_size;
	np = nullptr;
}

template <typename T>
Tnode<T>* Tree<T>::insert(const T& e) {
	Tnode<T>* np = _root;
	Tnode<T>* hot = nullptr;
	while (np) {
		hot = np;
		if (e < np->_e) np = np->_lc;
		else if (e > np->_e) np = np->_rc;
		else return np;
	}
	np = new Tnode<T>(e, hot);
	if (!hot) _root = np;
	else if (e < hot->_e) hot->_lc = np;
	else hot->_rc = np;
	++_size;
	return np;
}

template <typename T>
Tnode<T>* Tree<T>::search(const T& e) {
	Tnode<T>* np = _root;
	while (np) {
	}

}


template <typename T>
void Tree<T>::travelLevel() {
	cout << "travel level: ";
	if (!_root) return;
	queue<Tnode<T>*> Q;
	Q.push(_root);
	Tnode<T>* np = nullptr;
	while (!Q.empty()) {
		np = Q.front(); Q.pop();
		if (np->_lc) Q.push(np->_lc);
		if (np->_rc) Q.push(np->_rc);
		cout << np->_e << " ";
	}
	cout << endl;
}	

template <typename T>
void Tree<T>::travelPre() {
	cout << "travel preOrder: ";
	if (!_root) return;
	stack<Tnode<T>*> S;
	S.push(_root);
	Tnode<T>* np = nullptr;
	while (!S.empty()) {
		np = S.top(); S.pop();
		cout << np->_e << " ";
		if (np->_rc) S.push(np->_rc);
		if (np->_lc) S.push(np->_lc);
	}
	cout << endl;
}

template <typename T>
void Tree<T>::travelMedi() {
	cout << "travel mediOrder: ";
	if (!_root) return;
	stack<Tnode<T>*> S;
	auto left_down = [&](Tnode<T> *p) {
		S.push(p);
		while (p->_lc) {
			S.push(p->_lc);
			p = p->_lc;
		}
	};
	left_down(_root);
	Tnode<T> *np = nullptr;
	while (!S.empty()) {
		np = S.top(); S.pop();
		cout << np->_e << " ";
		if (np->_rc) left_down(np->_rc);
	}
	cout << endl;
}	

template <typename T>
void Tree<T>::travelPost() {
	cout << "travel postOrder: ";
	if (!_root) return;
	stack<Tnode<T>*> S;
	auto down = [&](Tnode<T> *p) {
		S.push(p);
		while (p->_lc) {
			S.push(p->_lc);
			p = p->_lc;
		}
	};
	down(_root);
	Tnode<T> *np = nullptr;
	int i = 0;
	while (!S.empty()) {
		if (++i == 100) return;
		np = S.top();
		if (np->_rc) down(np->_rc);
		else {
			cout << np->_e << " ";
			S.pop();
			while (np->_pa && np->_pa->_rc == np) {
				np = S.top();
				cout << np->_e << " ";
				S.pop();
			}
		}
	}
	cout << endl;
}

				


template <typename T>
void Tree<T>::show() const {
	cout << "size:" << _size << endl;
	if (!_root) return; 
	stack<Tnode<T>*> S;
	Tnode<T>* np = nullptr;
	int x = 0, y = 0;

	auto left_down = [&](Tnode<T>* p) {
		S.push(p);
		p->_y = y++;
		while (p->_lc) { 
			S.push(p->_lc);
			p = p->_lc;
			p->_y = y++;
		}
	};

	left_down(_root);
	while (!S.empty()) {
		np = S.top(); S.pop();

		ostringstream sout;
		sout << "[" << np->_e << "]";
		string stmp = sout.str();
		np->_len = stmp.size();

		np->_x = x;
		x += np->_len + 0;
		if (np->_rc) {
			y = np->_y + 1;
			left_down(np->_rc);
		}
	}
	cout << endl;

	queue<Tnode<T>*> Q;
	Q.push(_root);
	int lp, rp, mp;
	int row = 0, col = 0;
	vector<int> vi;
	while (!Q.empty()) {
		np = Q.front(); Q.pop();
		if (row+1 == np->_y) {
			++row;
			col = 0;
			cout << "\n";
			int len = vi.size();
			string s(vi[len-1]+1, ' ');
			for (int i = 0; i < len; ++i)
				s[vi[i]] = '|';
			cout << s << endl;
			vi.clear();
		}
		mp = np->_x;
		lp = rp = mp;
		if (np->_lc) {
			Q.push(np->_lc);
			lp = np->_lc->_x;
			vi.push_back(lp);
		}
		if (np->_rc) {
			Q.push(np->_rc);
			rp = np->_rc->_x 
				+ np->_rc->_len - 1;
			vi.push_back(rp);
		}

		for (; col <= rp; ++col) {
		 	if (col == mp) {
				cout << '[' << np->_e << ']';
				col += np->_len;
				continue;
			}
			else if (col < lp) {
				cout << " ";
			}
			else cout << '_';
		}
		--col;
	}
	cout << endl;
}
	
	
}; // namespace zlimbo

#endif // zbst.hpp
