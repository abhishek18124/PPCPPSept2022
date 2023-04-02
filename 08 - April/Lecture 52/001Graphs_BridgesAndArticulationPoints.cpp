/*

Input Format 

The first line of the input contains an integer n (1<=n<100000) - the number of vertices in the graph labelled from 1 to n
The second line of the input contains an integer m - the number of edges in the graph
The following m lines of the input contain two integers each representing a graph edge

*/


#include<iostream>
#include<vector>

using namespace std;

const int N = 1e5;

vector<int> g[N]; // represents the internal graph representation i.e. neighbourMap

vector<int>  d(N); // to store the discovered time of vertices 
vector<bool> v(N); // to track vertices that are visited during dfs
int tme = 1; // to track the current time

void dfs(int s) {

	// 1. mark the 's' vertex as visited
	v[s] = true;
	d[s] = tme;
	tme++;

	// 2. explore the vertex 's'
	vector<int> ngb_list = g[s];
	for(int ngb : ngb_list) {
		if(!v[ngb]) {
			// 'ngb' is not yet visited
			dfs(ngb);
		}
	}


}

int main() {

	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		// add an undirected edge between vertices u & v
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);

	for(int i=1; i<=n; i++) {
		cout << d[i] << " ";
	}

	cout << endl;

	return 0;
}