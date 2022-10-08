#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {
	for(int i=2; i<=n-1; i++) {
		if(n%i == 0) {
			// n is not a prime number
			return false;
		}
	}
	// n is a prime number
	return true;
}

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	if(isPrime(n)) {
		cout <<  n << " is prime" << endl;
	} else {
		cout << n << " is not prime" << endl;
	}

	return 0;
}