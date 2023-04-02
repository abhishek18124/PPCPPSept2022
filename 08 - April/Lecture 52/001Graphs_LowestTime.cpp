/*

Input Format 

The first line of the input contains an integer n (1<=n<100000) - the number of vertices in the graph labelled from 1 to n
The second line of the input contains an integer m - the number of edges in the graph
The following m lines of the input contain two integers each representing a graph edge

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int N = 1e5;

vector<int> g[N]; // represents the internal graph representation i.e. neighbourMap

vector<int>  d(N); // to store the discovered time of vertices 
vector<bool> v(N); // to track vertices that are visited during dfs
vector<int>  l(N); // to store the lowest time of vertices
int tme = 1; // to track the current time

vector<pair<int, int>> bridges;
set<int> articulation_points;

void dfs(int u, int par) {

	// 1. mark the 'u' vertex as visited
	v[u] = true;
	d[u] = tme;
	l[u] = d[u];
	tme++;
	int numChilds = 0;

	// 2. explore the vertex 'u'
	vector<int> ngb_list = g[u];
	for(int ngb : ngb_list) {
		if(!v[ngb]) {
			// 'ngb' is not yet visited
			numChilds++;
			dfs(ngb, u);
			l[u] = min(l[u], l[ngb]);

			if(l[ngb] > d[u]) {
				// u to ngb is a bridge
				bridges.push_back({u, ngb});
			}

			if(par != 0 and l[ngb] >= d[u]) {
				// u is a articulation point
				articulation_points.insert(u);
			}

		} else {
			// 'ngb' is already visted 
			if(ngb != par) {
				// u to ngb is a backedge
				l[u] = min(l[u], d[ngb]);
			}
		}


	}

	if(par == 0 and numChilds > 1) {
		// 'u' is an articulation point
		articulation_points.insert(u);
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

	dfs(1, 0);

	for(int i=1; i<=n; i++) {
		cout << d[i] << " ";
	}

	cout << endl;

	for(int i=1; i<=n; i++) {
		cout << l[i] << " ";
	}

	cout << endl;

	for(pair<int, int> b : bridges) {
		cout << b.first << " " << b.second << endl;
	}
	cout << endl;

	for(int ap : articulation_points) {
		cout << ap << endl;
	}

	return 0;
}