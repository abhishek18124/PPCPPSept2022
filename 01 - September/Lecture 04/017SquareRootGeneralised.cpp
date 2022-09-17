#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	int p;
	cout << "Enter p : ";
	cin >> p;

	double sq = 0; // to store the square root of 'n'

	int i = 0;
	double inc = 1;
	while(i <= p) {
		while(sq*sq <= n) {
			sq = sq + inc;
		}

		sq = sq - inc;
		inc = inc/10;
		i = i+1;
	}

	cout << "square root : " << sq << endl;
	
	return 0;
}