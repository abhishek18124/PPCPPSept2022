#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;
	while(i <= n) {

		// print i numbers
		int j = 1;
		int num = 1;
		while(j <= i) {
			cout << num << ' ';
			j++;
			num++;
		}

		cout << endl;
		i++;

	}

	return 0;
}