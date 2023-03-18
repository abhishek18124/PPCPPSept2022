/*

Implementation of graph traversal using

	1. depth first search (dfs)
	2. breadth first search (bfs)

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class graph {

	unordered_map<T, list<T>> neighbourMap; // to store the graph representation
	bool isDirected; // to indicate if the graph is directed or not

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v) {

			// adds an edge b/w vertex u and v
			
			neighbourMap[u].push_back(v);
			
			if(!isDirected) {
				neighbourMap[v].push_back(u);
			}

		}

		void dfsHelper(T s, unordered_set<T>& visited) {
			
			// mark 's' as visited

			visited.insert(s);

			// explore 's'

			cout << s << " ";

			// visited unvisited vertices reachable from 's'

			list<T> neighbourList = neighbourMap[s];
			for(T neighbour : neighbourList) {
				if(visited.find(neighbour) == visited.end()) {
					// neighbour is not yet visited
					dfsHelper(neighbour, visited);
				}
			}

		}


		void traverse() {
			unordered_set<T> visited; // to keep track of visited vertices
			int numComponents = 0;
			for(pair<T, list<T>> vertex : neighbourMap) { 
				T vertexLabel = vertex.first;
				if(visited.find(vertexLabel) == visited.end()) {
					
					// traverse the component containing the 'vertex'
					cout << "dfs(" << vertexLabel << ") : "; 
					dfsHelper(vertexLabel, visited);	
					numComponents++;
					cout << endl;
				}
			}

			cout << "numComponents = " << numComponents << endl;
		}

};

int main() {

	graph<char> g;

	g.addEdge('A', 'C');
	g.addEdge('A', 'D');
	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('C', 'F');
	g.addEdge('D', 'F');
	g.addEdge('D', 'G');
	g.addEdge('E', 'G');

	g.addEdge('H', 'J');
	g.addEdge('I', 'J');
	g.addEdge('J', 'K');
	g.addEdge('J', 'L');

	g.addEdge('M', 'N');
	g.addEdge('M', 'O');
	g.addEdge('N', 'P');
	g.addEdge('O', 'P');

	g.traverse();

	return 0;
}