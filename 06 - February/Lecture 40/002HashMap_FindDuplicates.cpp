#include<iostream>
#include<vector>

using namespace std;

void findDuplicate(vector<int> v) {

	int n = v.size();

	for(int i=0; i<n; i++) {
		v[v[i]%n] += n;
	}

	// for(int i=0; i<n; i++) {
	// 	cout << v[i] << " ";
	// }

	for(int i=0; i<n; i++) {
		if(v[i]/n > 1) {
			cout << i << " ";
		}
	}

	cout << endl;

}

int main() {

	vector<int> v = {1, 3, 1, 0, 2};

	findDuplicate(v);
	
	return 0;
}