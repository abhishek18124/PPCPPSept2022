/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is an integer.

*/

#include<iostream>
#include<list>

using namespace std;

class graph {
	
	int V;           // to store the number of vertices in the graph
	bool isDirected; // to indicate if the graph is directed  or not
	list<int>* arr;  // pointer  to the array representing the graph 
	
public:
	
	graph(int V, bool isDirected=false) {
		this->V = V;
		this->isDirected = isDirected;
		arr = new list<int>[V];
	}

	void addEdge(int u, int v) {

		// adds an edge b/w vertex u and v

		arr[u].push_back(v);
		if(!isDirected) {
			arr[v].push_back(u);
		}
	}

	void print() {
		
		// prints the adjacency list representation of the graph

		for(int i=0; i<V; i++) {
			cout << i << " : ";
			list<int> neighbourList = arr[i];
			for(int neighbour : neighbourList) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
	}

};

int main() {

	graph g(5);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);

	g.print();

	return 0;
}