/*

Given an directed graph, check if there exists a back-edge or not.

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

	public :

		void addEdge(T u, T v) {
			// add a directed edge between vertex 'u' and 'v'
			neighbourMap[u].push_back(v);
		}

		void topologicalSort() {

			queue<T> q; // to keep track of vertices w/o any dependencies
			unordered_map<T, int> inDegMap; // to store the mapping b/w the
			                                // vertices and their in-degrees

			// populate the inDegMap
			
			for(pair<T, list<T>> vertex : neighbourMap) {
				list<T> neighbourList = vertex.second;
				for(T neighbour : neighbourList) {
					// account for directed edge from 'vertex' to 'neighbour'
					inDegMap[neighbour]++;
				}
			}

			// initialise queue with vertices w/o 
			// any dependency i.e. zero in-degree
			
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				if(inDegMap.find(vertexLabel) == inDegMap.end()) {
					// vertex with 'vertexLabel' has no dependency
					q.push(vertexLabel);
				}
			}

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				// explore 'front'

				cout << front << " ";
				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					inDegMap[neighbour]--;
					if(inDegMap[neighbour] == 0) {
						// all the dependencies of neighbour has been resolved
						q.push(neighbour);
					}
				}
				
			}

			cout << endl;

		}

};


int main() {

	graph<char> g;

	g.addEdge('I', 'B');
	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('A', 'D');
	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('D', 'C');
	g.addEdge('D', 'E');
	g.addEdge('D', 'F');
	g.addEdge('D', 'G');
	g.addEdge('D', 'H');
	g.addEdge('E', 'G');
	g.addEdge('F', 'C');
	g.addEdge('G', 'H');
	g.addEdge('H', 'F');
		
	g.topologicalSort();

	return 0;
}