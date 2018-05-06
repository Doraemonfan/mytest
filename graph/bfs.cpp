#include <iostream>
#include <queue>

using namespace std;

template <typename T> class Vertex;
template <typename T> class Edge;
template <typename T> class Graph;

enum VISIT { NO_VISIT, NOW_VISIT, VISITED };
enum { maxN = 1000 };

template <typename T>
class Edge {

public:
	Edge(Vertex<T> *vp, int w);
	Vertex<T> *_vp;
	int _weight;
	Edge<T> *_next;
};

template <typename T>
Edge<T>::Edge(Vertex<T> *vp, int w):
	_vp(vp), _weight(w), _next(nullptr)
{ }

template <typename T>
class Vertex {

public:
	Vertex(T e);
	T _value;
	int _distance;
	int _key;
	Vertex<T> *_parent;
	VISIT _visit;	
	Vertex<T> *_next;
	Edge<T> *_Adj;
};

template <typename T>
Vertex<T>::Vertex(T e):
	_value(e), 
	_next(nullptr),
	_Adj(nullptr)
{ }

template <typename T>
class Graph {

public:
	Graph();
	~Graph();
	bool insertV(const T &e);
	bool insertE(const T &ue, const T &ve, int w = 1);
	void reset();
	void bfs(const T &se);
	Vertex<T>* findV(const T &ue) const;
	void clear();
	void show();
	Vertex<T> *_Vhead;
	Vertex<T> *_Vtail;
};

template <typename T>
Graph<T>::Graph():
	_Vhead(nullptr), _Vtail(nullptr)
{ }

template <typename T>
Graph<T>::~Graph() { clear(); }

template <typename T>
void Graph<T>::clear() {
	Vertex<T> *up = _Vhead;
	while (up) {
		_Vhead = up->_next;
		Edge<T> *ap = up->_Adj;
		Edge<T> *ep = ap;
		while (ep) {
			ap = ep->_next;
			delete ep;
			ep = ap;
		}
		up = _Vhead;
	}
}

template <typename T>
bool Graph<T>::insertV(const T &e) {
	
	Vertex<T> *up = new Vertex<T>(e);
	if (_Vtail)
		_Vtail->_next = up;
	else
		_Vhead = up;
	_Vtail = up;
	return true;
}

template <typename T>
Vertex<T>* Graph<T>::findV(const T &ue) const {
	Vertex<T> *up = _Vhead;
	while (up && up->_value != ue)
		up = up->_next;
	return up;
}

template <typename T>
bool Graph<T>::insertE(const T &ue, const T &ve, int w) {
	Vertex<T> *up = findV(ue);
	Vertex<T> *vp = findV(ve);
	if (!up || !vp) std::abort();
	Edge<T> *ap = up->_Adj;
	if (!ap) {
		up->_Adj = new Edge<T>(vp,  w);
		return true;
	}
	Edge<T> *tmp = ap;
	while (ap) {
		if (ap->_vp->_value == ve)
			return false;
		tmp = ap;
		ap = ap->_next;
	}
	tmp->_next = new Edge<T>(vp, w);
	return true;
}
template <typename T> 
void Graph<T>::reset() {
	Vertex<T> *up = _Vhead;
	while (up) {
		up->_distance = maxN;
		up->_key = maxN;
		up->_visit = NO_VISIT;
		up->_parent = nullptr;
		up = up->_next;
	}
}

template <typename T>
void Graph<T>::bfs(const T &se) {
	reset();
	Vertex<T> *sp = findV(se);
	if (!sp) std::abort();
	sp->_distance = 0;
	sp->_visit = NOW_VISIT;
	queue<Vertex<T>*> pQ;
	cout << sp->_value << "(" << sp->_distance << ") ";
	pQ.push(sp);
	while (!pQ.empty()) {
		Vertex<T> *up = pQ.front(); pQ.pop();
		Edge<T> *ap = up->_Adj;
		while (ap) {
			Vertex<T> *vp = ap->_vp;
			if (vp->_visit == NO_VISIT) {
				vp->_distance = up->_distance + 1;
				vp->_parent = up;
				vp->_visit = NOW_VISIT;
				pQ.push(vp);
			//	cout << " #" << vp->_value << "# ";
				cout << vp->_value << "("
					<< vp->_distance << ") ";
			}
			ap = ap->_next;
		}
		up->_visit = VISITED;
	}
}
	
template <typename T>
void Graph<T>::show() {
	Vertex<T> *up = _Vhead;
	while (up) {
		cout << up->_value << " : ";
		Edge<T> *ap = up->_Adj;
		while (ap) {
			cout << ap->_vp->_value 
				<< "(" << ap->_weight << ") ";
			ap = ap->_next;
		}
		cout << endl;
		up = up->_next;
	}
}

void test1() {
	Graph<int> g;
	for (int i = 0; i < 8; ++i)
		g.insertV(i);
	auto a = [&](int u, int v) { g.insertE(u, v); };
	a(0, 1);
	a(1, 2);
	a(2, 1); a(2, 3);
	a(3, 2); a(3, 4); a(3, 5);
	a(4, 3); a(4, 5); a(4, 6); a(4, 7);
	a(5, 3); a(5, 4); a(5, 6); 
	a(6, 4); a(6, 5); a(6, 7);
	a(7, 4); a(7, 6);

	g.bfs(3);
	cout << endl;
	g.show();
}

int main() {
	
	test1();

	return 0;
}
