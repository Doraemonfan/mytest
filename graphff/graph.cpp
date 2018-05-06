// 2018.4.12
// graph
// Graph adjective 
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <memory>
#include <initializer_list>


using namespace std;
const int IMAX = 0x7fffffff;
const int IMIN = 0x80000000;

enum COLOR { WHITE, GRAY, BLACE };

class Vertex {
public:
	COLOR color;
	Vertex *parent;
	int distance;
	int key;

	Vertex(COLOR c = WHITE, Vertex *p = nullptr,
		int d = IMAX, int k = IMAX):
		color(c), parent(p), distance(d), key(k)
	{ }


};

class Edge {

public:
	int v;
	int weight;
	
	Edge(int u, int w = 1):
		v(u), weight(w)
	{ }
};

class Graph {

public:
	using GV = std::vector<Vertex>;
	using GE = std::vector<vector<Edge>>;
	
	GV V;
	GE Adj;

	Graph(int n = 0): 
		V(std::move(GV(n))),
		Adj(std::move(GE(n))) 
	{ }

	~Graph() = default;

	void insertEdge(int u, int v);
	void insertEdge(int u, initializer_list<int> &&lst);
	void show();
	void bfs(int v);
	void dfs();

};

void Graph::insertEdge(int u, int v) 
{
	if (u < 0 || u >= V.size()) return;
	if (v < 0 || v >= V.size()) return;
	Adj[u].push_back(std::move(Edge(v)));
}

void Graph::insertEdge(int u, initializer_list<int> &&lst) 
{
	if (u < 0 || u >= V.size()) return;
	for (auto &v: lst)
		if (v > 0 && v < V.size()) 
			Adj[u].push_back(std::move(Edge(v)));
}

void Graph::bfs(int v) 
{
	for (int i = 0; i < V.size(); ++i) 
	{
		V[i].color = WHITE;
		V[i].parent = nullptr;
		V[i].distance = IMAX;
	}
	V[v].distance = 0;
	queue<int> QV;
	QV.push(v);
	while (!QV.empty()) {
		int u = QV.top(); QV.pop();
		u.color = GRAY;
		for (int i = 0; i < Adj[u].size(); ++i) 
		{
			int v = Adj[u][i].v;
			if (V[u].color = white) {
				V[u].distance = V[u].distance + 1;
				V[u].parent = V[
}

void Graph::show() 
{
	for (int i = 0; i < V.size(); ++i) 
	{
		std::cout << i << " : ";
		for (int j = 0; j < Adj[i].size(); ++j)
			std::cout << Adj[i][j].v << "(" 
				<< Adj[i][j].weight << ")  ";
		std::cout << std::endl;
	}
}

int main() 
{
	using LS = initializer_list<int>;
	Graph G(10);
	G.insertEdge(0, LS({1, 2, 3, 4, 5}));
	LS l = {4, 5, 6, 7, 8, 9};
	G.insertEdge(1, std::move(l));
	G.show();
	cout << "\n" << IMAX << "\n" << IMIN << endl;
	return 0;
}

