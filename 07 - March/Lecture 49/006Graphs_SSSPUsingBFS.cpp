/*

Computing SSSP using the BFS algorithm in an unweighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {

	map<T, list<T>> neighbourMap; // to store the graph representation
	bool isDirected; // to indicate if the graph is directed or not

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v) {

			// adds an edge b/w vertex u and v
			
			neighbourMap[u].push_back(v);
			
			if(!directed) {
				neighbourMap[v].push_back(u);
			}

		}

		void bfs(T s, T d) {
			
			map<T, int> distMap; // to store the mapping between vertices &
			                     // their shortest dist from the src vertex
			distMap[s] = 0;

			unordered_set<T> visited; // to keep track of visited vertices
			queue<T> q; // to keep track of visited & un-explored vertices

			// mark 's' as visited
			visited.insert(s);
			q.push(s);

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				// explore 'front'

				// todo ...
				
			}
		}
};


int main() {

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 8);

	return 0;
}