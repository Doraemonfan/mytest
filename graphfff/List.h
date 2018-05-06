#ifndef __LINK_H__
#define __LIST_H__

#include <iostream>
#include <stdexcept>

template <typename T> class ListNode;
template <typename T> class List;

//////////////////////////////////////////
// 
//	ListNode<T>

template <typename T>
class ListNode {
	
	friend class List<T>;
	template <typename T2>
	friend std::ostream& operator<<(
		std::ostream &out, const ListNode<T2> &ln);
protected:
	ListNode() = default;
	ListNode(const T& e,
		ListNode<T> *p, 
		ListNode<T> *s);
public:
	~ListNode() = default;
	ListNode<T>& operator=(const T& e);
private:
	T _value;
	ListNode<T> *_prec;
	ListNode<T> *_succ;
};


template <typename T>
ListNode<T>::ListNode(const T& e, 
		ListNode<T> *p, 
		ListNode<T> *s ):
	_value(e), _prec(p), _succ(s) 
{ }

template <typename T>
ListNode<T>& ListNode<T>::operator=(const T& e) {
	_value = e;
	return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream &out, 
		const ListNode<T> &ln) {
	out << ln._value;
}
//
//////////////////////////////////////////


///////////////////////////////////////
//	
//	List<T>

template <typename T>
class List {

public:
	using size_t = unsigned;
	
	List();
	~List();
	ListNode<T>& operator[](size_t r);
	
	void clear();
	void push_back(const T &e);
	void push_front(const T &e);
	void insert(size_t r, const T &e);
	void erase(size_t r);
	void show();

private:
	size_t _size;
	ListNode<T> *_head;
	ListNode<T> *_tail;
};


template <typename T>
List<T>::List():
	_size(0), 
	_head(new ListNode<T>()), 
	_tail(new ListNode<T>())
{ 
	_head->_prec = nullptr;
	_tail->_succ = nullptr;
	_head->_succ = _tail;
	_tail->_prec = _head;
}

template <typename T>
List<T>::~List() {
	clear();
	delete _head;
	delete _tail;
}

template <typename T>
void List<T>::clear() {
	ListNode<T> *tmp = _head->_succ;
	ListNode<T> *dtmp = tmp;
	while (tmp != _tail) {
		tmp = dtmp->_succ;
		delete dtmp;
		dtmp = tmp;
	}
	_size = 0;
	_head->_succ = _tail;
	_tail->_prec = _head;
}

template <typename T>
ListNode<T>& List<T>::operator[](size_t r) {
	ListNode<T> *tmp = _head->_succ;
	if (r >= _size) 
		std::abort();
	while (r--) 
		tmp = tmp->_succ;
	return *tmp;
}

template <typename T>
void List<T>::insert(size_t r, const T &e) {
	ListNode<T> *rp = &(*this)[r];
	ListNode<T> *tmp = 
		new ListNode<T>(e, rp->_prec, rp);
	rp->_prec->_succ = tmp;
	rp->_prec = tmp;
	++_size;
}

template <typename T>
void List<T>::push_back(const T &e) {
	ListNode<T> *tmp = 
		new ListNode<T>(e, _tail->_prec, _tail);
	_tail->_prec->_succ = tmp;
	_tail->_prec = tmp;
	++_size;
}

template <typename T>
void List<T>::push_front(const T &e) {
	ListNode<T> *tmp =
		new ListNode<T>(e, _head, _head->_succ);
	_head->_succ->_prec = tmp;
	_head->_succ = tmp;
	++_size;
}	
		
template <typename T>
void List<T>::erase(size_t r) {
	ListNode<T> *rp = &(*this)[r];
	ListNode<T> *tmp;
	if (rp == _tail) return;
	rp->_prec->_succ = rp->_succ;
	rp->_succ->_prec = rp->_prec;
	delete rp;
	--_size;
}
			
template <typename T>
void List<T>::show() {
	std::cout << "size = " << _size << "\n elem: ";
	for (size_t i = 0; i < _size; ++i) 
		std::cout << (*this)[i] << " ";	
	std::cout << std::endl;
}

#endif
