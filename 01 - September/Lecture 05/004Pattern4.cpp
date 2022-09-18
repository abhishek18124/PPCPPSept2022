#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;

	while(i <= n) {

		// print i nos.

		int j = 1;

		int num = i%2 == 0 ? 0 : 1;

		while(j <= i) {
			cout << num << " ";
			// num = !num;
			num = 1-num;
			j++;
		}

		i++;
		cout << endl;

	}

	return 0;
}