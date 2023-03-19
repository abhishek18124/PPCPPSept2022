/*

Snake and Ladders Game

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

	public :

		void addEdge(T u, T v) {
			// insert a directed edge between vertex 'u' and 'v'
			neighbourMap[u].push_back(v);
		}

		void print() {
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<T> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(T neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

};

int minDiceThrows(int n, 
	              vector<pair<int,int>> snakes, 
	              vector<pair<int,int>> ladders) {
	
	// todo ...

}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {{17, 4}, 
									  {20, 6}, 
									  {24, 16}, 
									  {32, 30}, 
									  {34, 12}};

	vector<pair<int, int>> ladders = {{2, 15}, 
	                                  {5, 7}, 
	                                  {9, 27}, 
	                                  {18, 29}, 
	                                  {25, 35}};
	
	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}