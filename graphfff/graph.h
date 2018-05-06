#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <initialzer_list>
#include "List.h"


template <typename T> class Vertex;
template <typename T> class Graph;
template <typename T> class Edge;

////////////////////////////////////////////////////////
//
//	Edge<T>
//

template <typename T>
class Edge {

protected:
	Edge(Vertex<T> *vp, int w = 1);
	~Edge() = default;
private:
	Vertex<T> *_vp;
	int _weight;
};

template <typename T>
Edge<T>::Edge(Vertex<T> *vp, int w = 1):
	_vp(vp), _weight(w),
{ }

//
////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
//
//	Vertex<T>
//

template <typename T>
calss Vertex {

friend class Graph<T>;

public:
	~Vertex() = default;

protected:
	enum VISIT { NO_VISIT, NOW_VISIT, VISITED };
	enum { maxN = 1000, minN = -1000 };

	Vertex(const T &e);
	void init();
private:
	T _value;
	int _distance;
	Vertex<T> *_parent;
	int _key;
	VISIT _visit; 
	List<Edge> Adj;
};

void Vertex<T>::init() {
	_distance = maxN;
	_parent = nullptr;
	_key = maxN;
	_visit = NO_VISIT;
}

template <typename T>
Vertex<T>::Vertex(const T &e): _value(e) { init() };

//
////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//
//	Graph<T>
//

template <typename T>
class Graph {

public:
	Graph() = default;
	Graph(std::initializer_list<T> &lst);
	~Graph() = default;

	void insertVertex(const T &ue);
	void insertVertex(std::initializer_list<T> &lst);
	void insertEdge(const T &ue, 
			const T &ve, int w = 1);
	void removeVertex(const T &ue);
	void removeEdge(const T &ue, const T &ve);

	void edge(const T &u, const T &v);
	Vertex<T>& find(const T &e);

private:
	List<Vertex<T>> _V;
}

template <typename T>
Graph<T>::Graph(std::initializer_list<T> &lst) {
	for (auto &i : lst) 
		insertVertex(i);
}

template <typename T>
Vertex<T>* Graph<T>::find(const T &e) {
	return _V.find(Vertex<T>(e));
}

template <typename T>
bool Graph<T>::insertVertex(const T &e) {
	Vertex<T> u(e);
	if (_V.find(u))
		return false;
	_v.push_back(u);
	return true;
}

template <typename T>
void Graph<T>::insertVertex(
		std::initializer_list<T> &lst) {
	for (auto &i : lst) 
		insertVertex(i);
}

template <typename T>
bool Graph<T>::insertEdge(const T &ue, const T &ve, int w = 1) {
	Vertex<T> *up = _V.find(Vertex<T>(ue));
	Vertex<T> *vp = _V.find(Vertex<T>(ve));
	if (up && vp) {
		Edge<T> eg(ve);
		up->Adj.push_back(edge<T>(vp));
		return true;
	}
	else return false;
}

template <typename T>
bool Graph<T>::removeVertex(const T &ue) {
	Vertex<T> *up = _V.find(Vertex<T>(ue));
	if (!up) return false;
	for (int i = 0; i < _V.size(); ++i) {
		for (int j = 0; j < _V[i].size(); ++j) {
			Edge<T> 
			if (_V[i].Adj[j]._vp == up)
				_V[i].Adj[j].erase
//
///////////////////////////////////////////////////////////////// 
void test {
	Graph<int> G;
	for (int i = 0; i < 20; ++i) 
		G.insertVertex(i);
	G.insertEdge(1, 2);
	G.insertEdge(2, 3);
	G.removeEdge(1, 2);
	G.removeVertex(4);
}

#endif
