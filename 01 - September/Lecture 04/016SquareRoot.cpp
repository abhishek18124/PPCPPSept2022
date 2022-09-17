#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	double sq = 0; // to store the square root of 'n'

	while(sq*sq <= n) {
		sq = sq + 1;
	}

	sq = sq - 1;

	while(sq*sq <= n) {
		sq = sq + 0.1;
	}

	sq = sq - 0.1;

	while(sq*sq <= n) {
		sq = sq + 0.01;
	}

	sq = sq - 0.01;

	cout << "square root : " << sq << endl;
	
	return 0;
}