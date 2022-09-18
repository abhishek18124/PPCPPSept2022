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

		// print i-1 numbers starting with 2i-2 in the decreasing order
		// num = 2*i - 2;
		num = num-2;
		int l = 1;
		while(l <= i-1) {
			cout << num << " ";
			l++;
			num--;
		}

		i++;
		cout << endl;

	}

	return 0;
}