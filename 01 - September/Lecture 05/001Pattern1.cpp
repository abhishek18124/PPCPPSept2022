#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;
	while(i <= n) {

		// print i stars
		int j = 1;
		while(j <= i) {
			cout << "*";
			j++;
		}

		cout << endl;
		i++;

	}

	return 0;
}