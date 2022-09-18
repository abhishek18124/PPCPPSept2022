#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;

	while(i <= n) {

		// print n-i spaces
		int j = 1;
		while(j <= n-i) {
			cout << "  ";
			j++;
		}

		// print i numbers starting with i in the increasing order
		int num = i;
		int k = 1;
		while(k <= i) {
			cout << num << " ";
			k++;
			num++;
		}

		i++;
		cout << endl;

	}

	return 0;
}