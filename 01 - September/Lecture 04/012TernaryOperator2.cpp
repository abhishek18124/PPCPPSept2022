#include<iostream>
#include<climits>

using namespace std;

int main() {

	int i;
	cin >> i;
	
	int j = i%2 == 0 ? 1 : 0;
	
	cout << "j : " << j << endl;

	return 0;
}