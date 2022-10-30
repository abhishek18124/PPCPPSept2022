#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	// iterate over all the possible starting indices
	for(int i=0;  i<=n-1; i++) {
		// iterate over all the possible ending indices
		for(int j=i; j<=n-1; j++) {
			cout << str.substr(i, j-i+1) << endl;
		}
		cout << endl;
	}
	
	return 0;
}