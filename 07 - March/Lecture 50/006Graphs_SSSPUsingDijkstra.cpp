/*

Computing SSSP using the Dijkstra's algorithm in a weighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<climits>

using namespace std;

template <typename T>
class graph {

	map<T, list<pair<T, int>>> neighbourMap; // to store the graph representation
	bool isDirected; // to indicate if the graph is directed or not

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v, int w) {
			// add a weighted-edge b/w u and v 
			neighbourMap[u].push_back({v, w});
			if(!isDirected) {
				neighbourMap[v].push_back({u, w});
			}
		}

		void print() {
			for(pair<T, list<pair<T, int>>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<pair<T, int>> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(pair<T, int> neighbour : neighbourList) {
					T neighbourLabel = neighbour.first;
					int edgeWeight = neighbour.second;
					cout << "(" << neighbourLabel << ", " << edgeWeight << ") ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void dijkstra(T s) {

			map<T, int> distMap; // to store a mapping b/w vertices and their
			                     // shortest distances from the source vertex
			for(pair<T, list<pair<T, int>>> vertex: neighbourMap) {
				T vertexLabel = vertex.first;
				distMap[vertexLabel] = INT_MAX;
			}
			distMap[s] = 0;

			unordered_set<T> explored; // to keep track of explored vertices

			set<pair<int, T>> minHeap; // to keep track of unexplored vertices
			for(pair<T, int> vertex : distMap) {
				T vertexLabel = vertex.first;
				int vertexDist = vertex.second;
				minHeap.insert({vertexDist, vertexLabel});
			}

			while(!minHeap.empty()) {

				pair<int, T> minVertex = *minHeap.begin();
				minHeap.erase(minHeap.begin());

				int minVertexDist = minVertex.first;
				T minVertexLabel  = minVertex.second;

				list<pair<T, int>> neighbourList = neighbourMap[minVertexLabel];
				for(pair<T, int> neighbour : neighbourList) {
					T neighbourLabel = neighbour.first;
					int edgeWeight = neighbour.second;
					if(explored.find(neighbourLabel) == explored.end() && 
					   distMap[neighbourLabel] > distMap[minVertexLabel] + edgeWeight) {

						// relax the edge between the minVertexLabel and neighbourLabel

						// update the distance of the neighbourLabel in the minHeap
						auto it = minHeap.find({distMap[neighbourLabel], neighbourLabel});
						minHeap.erase(it);
						minHeap.insert({distMap[minVertexLabel]+edgeWeight, neighbourLabel});

						// update the distance of the neighbourLabel in the distMap
						distMap[neighbourLabel] = distMap[minVertexLabel] + edgeWeight;

					}
				}
				explored.insert(minVertexLabel);
			}

			for(pair<T, int> vertex : distMap) {
				T vertexLabel = vertex.first;
				int vertexDist = vertex.second;
				cout << vertexLabel << " " << vertexDist << endl;
			}
			cout << endl;
		}

};

int main() {

	graph<char> g;

	g.addEdge('A', 'B', 10);
	g.addEdge('A', 'C', 5);
	g.addEdge('B', 'C', 3);
	g.addEdge('B', 'D', 1);
	g.addEdge('C', 'D', 9);
	g.addEdge('C', 'E', 2);
	g.addEdge('D', 'E', 8);

	g.print();

	g.dijkstra('A');

	return 0;
}