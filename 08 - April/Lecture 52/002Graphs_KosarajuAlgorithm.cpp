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

vector<int> g[N]; // adjacency list
vector<int> revG[N]; // adjacency list
vector<int> tp_ordering; // to store topological ordering 
vector<bool> v(N); // to track visited vertices
vector<int> c(N); // to store color

void topological_sort(int u) {
	v[u] = true;
	for(int ngb : revG[u]) {
		if(!v[ngb]) {
			topological_sort(ngb);
		}
	}
	tp_ordering.push_back(u);
}
void dfs(int u, int color) {
	v[u] = true;
	c[u] = color;
	for(int ngb : g[u]) {
		if(!v[ngb]) {
			dfs(ngb, color);
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		// add a directed edge from vertex u to v
		g[u].push_back(v);
		revG[v].push_back(u);
	}

	// 2. apply topological sort on reversed (transposed) graph

	for(int i=1; i<=n; i++) {
		if(!v[i]) {
			topological_sort(i);
		}
	}

	reverse(tp_ordering.begin(), tp_ordering.end()); // otherwise use a list and build it using push_front as done earlier

	for(int i=0; i<tp_ordering.size(); i++) {
		cout << tp_ordering[i] << " ";
	}

	cout << endl;

	// 3. iterate over sink node vertices and apply dfs to count scc

	// fill(v.begin(), v.end(), false);

	for(int i=0; i<v.size(); i++) {
		v[i] = false;
	}

	int scc = 0;
	int color = 0;
	for(auto u : tp_ordering) {
		if(!v[u]) {
			dfs(u, color);
			scc++;
			color++;
		}
	}

	cout << scc << endl;

	for(int i=1; i<=n; i++) {
		cout << i << " " << c[i] << endl;
	}

	cout << endl;

	return 0;
}