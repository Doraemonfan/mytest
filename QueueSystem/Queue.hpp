//
// Queue.hpp
// QueueSystem
// 2018/4/25
//

#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include "Event.hpp"

template <typename T>
class Queue {

public:
	Queue();
	~Queue();
	T* dequeue();
	T* enqueue(const T& node);
	Event* orderEnqueue(const Event& event);
	void show();
	void clear();
	int length();
	bool empty() { return _head == _tail; }
private:
	T *_head;
	T *_tail;
};

template <typename T>
inline Queue<T>::Queue() {
	_head = new T;
	if (!_head) abort();
	_tail = _head;
}

template <typename T>
inline Queue<T>::~Queue() {
	clear();
	delete _head;
}

template <typename T>
void Queue<T>::clear() {
	T* new_node = _head->_next;
	while (new_node) {
		_head->_next = new_node->_next;
		delete new_node;
		new_node = _head->_next;
	}
	_tail = _head;
}

template <typename T>
int Queue<T>::length() {
	T* new_node = _head->_next;
	int len = 0;
	while (new_node) {
		++len;
		new_node = new_node->_next;
	}
	return len;
}

template <typename T>
T* Queue<T>::dequeue() {
	T* ret = _head->_next;
	if (ret) {
		_head->_next = ret->_next;
		if (!(ret->_next))
			_tail = _head;
	}
	return ret;
}
	
template <typename T>
inline T* Queue<T>::enqueue(const T& node) {
	T* new_node = new T(node);
	if (!new_node) abort();
	_tail->_next = new_node;
	_tail = new_node;
	return _head;
}

template <typename T>
Event* Queue<T>::orderEnqueue(const Event& event) {
	Event* new_node = new Event(event);
	if (!new_node) abort();
	T* hot = _head;
	while (hot->_next && 
		hot->_next->_occur_time < new_node->_occur_time)
		hot = hot->_next;
	new_node->_next = hot->_next;
	hot->_next = new_node;
	if (!(new_node->_next))
		_tail = new_node;
	return _head;
}

template <typename T>
void Queue<T>::show() {
	T* new_node = _head->_next;
	int i = 0;
	while (new_node) {
	//	std::cout << i++ << " # ";
		new_node->show();
		new_node = new_node->_next;
	}
}

#endif
