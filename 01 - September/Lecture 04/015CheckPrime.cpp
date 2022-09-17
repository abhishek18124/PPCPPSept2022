#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	int i = 2;
	double sq = sqrt(n);

	while(i <= sq) {
		if(n%i == 0) {
			// n is not prime
			cout << n << " is not prime" << endl;
			break;
		}
		i = i+1;
	}

	if(i > sq) {
		cout << n << " is prime" << endl;
	}

	return 0;
}