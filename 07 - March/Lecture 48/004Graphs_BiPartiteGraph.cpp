/*

Given an undirected graph, check if it is bipartite or not.

*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class graph {
	
	unordered_map<T, list<T>> neighbourMap; // to store the graph representation
	
	public :

		void addEdge(T u, T v) {

			// adds an edge b/w vertex u and v
			
			neighbourMap[u].push_back(v);
			neighbourMap[v].push_back(u);
		
		}
		
		bool bfsHelper(T source, unordered_map<T, int>& colorMap) {

			queue<T> q; // to keep track of unexplored & colored vertices

			// color the 'source' vertex
			colorMap[source] = 0; 
			q.push(source);

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				// explore 'front'

				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					if(colorMap.find(neighbour) == colorMap.end()) {
						// neighbour is not yet visited (colored)
						colorMap[neighbour] = 1-colorMap[front];
						q.push(neighbour);
					} else {
						// neighbour is already visited (colored)
						if(colorMap[front] == colorMap[neighbour]) {
							// componenet is not bipartite
							return false;
						}
					}
				}
				
			}

			return true;

		}

		bool isBiPartite() {
			bool flag = true; // assume graph is a biparite
			unordered_map<T, int> colorMap; // to store the mapping between 
			                                // the vertices and their color
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				if(colorMap.find(vertexLabel) == colorMap.end()) {
					// 'vertexLabel' not colored, hence not visited
					if(bfsHelper(vertexLabel, colorMap) == false) {
						// component is not bipartite, therefore graph is not bipartite
						flag = false;
						break;
					}	
				}
			}

			return flag;
		}
};


int main() {

	graph<char> g;

	// g.addEdge('A', 'B');
	// g.addEdge('A', 'C');
	// g.addEdge('B', 'D');
	// g.addEdge('B', 'E');
	// g.addEdge('C', 'E');
	// g.addEdge('C', 'F');


	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'D');
	g.addEdge('C', 'E');
	g.addEdge('D', 'E');
	
	g.isBiPartite() ? cout << "bipartite!" << endl :
	                  cout << "not bipartite!" << endl;

	return 0;
}