/*

Computing SSSP using the Bellman Ford's algorithm in a weighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<vector>
#include<climits>

using namespace std;

template <typename T>
class edge {
	public :

		T u;
		T v;
		int w;

		edge(T u, T v, int w) {
			this->u = u;
			this->v = v;
			this->w = w;
		}
};

template <typename T>
class graph {

	set<T>  vertexSet;        // to store the graph representation
	vector<edge<T>> edgeList; // to store the graph representation

	public :

		void addEdge(T u, T v, int w) {
			// add an edge of weight 'w' b/w 'u' and 'v' 
			edgeList.push_back(edge<T>(u, v, w));
			vertexSet.insert(u);
			vertexSet.insert(v);
		}

		void bellmanFord(T s) {

			map<T, int> distMap; // to store a mapping b/w vertices and their
			                     // shortest distances from the source vertex
			for(T vertex: vertexSet) {
				distMap[vertex] = INT_MAX;
			}
			distMap[s] = 0;

			int V = vertexSet.size();
			for(int i=1; i<=V-1; i++) {
				for(edge<T> e : edgeList) {
					if(distMap[e.u] != INT_MAX && 
					   distMap[e.u]+e.w < distMap[e.v]) {
						// relax the edge from vertex u to v
						distMap[e.v] = distMap[e.u]+e.w;
					}
				}
			}

			for(edge<T> e : edgeList) {
				if(distMap[e.v] > distMap[e.u]+e.w) {
					// graph contains a negative weight cycle
					exit(0);
				}
			}

			for(pair<T, int> p : distMap) {
				cout << "(" << p.first << ", " << p.second << ")" << endl;
			}

		}
};

int main() {

	graph<char> g;

	g.addEdge('A', 'B', 1);
	g.addEdge('C', 'B', -3);
	g.addEdge('B', 'C', 2);

	g.bellmanFord('A');

	return 0;
}