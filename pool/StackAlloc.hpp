//
// StackAlloc.hpp
// pool
// 2018/5/21
// zlimbo
//

#ifndef __STACKALLOC_HPP__
#define __STACKALLOC_HPP__

#include <memory>
using std::allocator;

template <typename T>
struct StackNode_ {
	T _data;
	StackNode_ *_prev;
};

template <typename T, typename Alloc = std::allocator<T>>
class StackAlloc {

public:
	using Node = StackNode_<T>;
	using allocator = 
		typename Alloc::template rebind<Node>::other;
	
	StackAlloc() { _head = nullptr; }
	~StackAlloc() { clear(); }

	bool empty() const { return _head == nullptr; }
	void clear() {
		Node *curr = _head;
		while (curr) {
			Node *tmp = curr->_prev;
			_allocator.destroy(curr);
			_allocator.deallocate(curr, 1);
			curr = tmp;
		}
		_head = nullptr;
	}

	void push(const T &element) {
		Node *newNode = _allocator.allocate(1);
		_allocator.construct(newNode, Node());
		newNode->_data = element;
		newNode->_prev = _head;
		_head = newNode;
	}

	T pop() {
		T result = _head->_data;
		Node *tmp = _head->_prev;
		_allocator.destroy(_head);
		_allocator.deallocate(_head, 1);
		_head = tmp;
		return result;
	}

	T top() const { return _head->data; }

private:
	allocator _allocator;
	Node *_head;
};

#endif // StackAlloc.hpp
