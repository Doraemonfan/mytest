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
	Event* order_enqueue(const Event& event);
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
	_head = new T(0, 0);
	if (!_head) exit(-1);
	_tail = _head;
}

template <typename T>
inline Queue<T>::~Queue() {
	clear();
	delete _head;
}

template <typename T>
void Queue<T>::clear() {
	T* temp = _head->_next;
	if (!temp) exit(-1);
	while (temp) {
		_head->_next = temp->_next;
		delete temp;
		temp = _head->_next;
	}
	_tail = _head;
}

template <typename T>
int Queue<T>::length() {
	T* temp = _head->_next;
	if (!temp) exit(-1);
	int len = 0;
	while (temp) {
		++len;
		temp = temp->_next;
	}
	return len;
}

template <typename T>
T* Queue<T>::dequeue() {
	T* ret = _head->next;
	if (!ret) exit(-1);
	if (ret) {
		_head->next = ret->next;
		if (!(ret->next))
			_tail = _head;
	}
	return ret;
}
	
template <typename T>
inline T* Queue<T>::enqueue(const T& node) {
	T* temp = new T(node);
	if (!temp) exit(-1);
	_tail->_next = temp;
	_tail = temp;
	return _head;
}

template <typename T>
Event* Queue<T>::order_enqueue(const Event& event) {
	Event* temp = new Event(event);
	if (!temp) exit(-1);
	T* hot = _head;
	while (hot->_next && 
		hot->_next->_occur_time < temp->_occur_time)
		hot = hot->_next;
	temp->_next = hot->_next;
	hot->_next = temp;
	if (!(temp->_next))
		_tail = temp;
	return _head;
}

template <typename T>
void Queue<T>::show() {
	T* temp = _head->_next;
	if (!temp) exit(-1);
	int i = 0;
	while (temp) {
		std::cout << i++ << " # ";
		temp->show();
		temp = temp->_next;
	}
}

#endif
