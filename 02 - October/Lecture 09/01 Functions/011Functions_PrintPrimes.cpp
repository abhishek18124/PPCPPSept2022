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


void printPrimes(int N) {
	int cnt = 0; // to track no. of prime numbers printed so far
	int n = 2;
	while(true) {
		if(isPrime(n)) {
			cout << n << " ";
			cnt++;
			if(cnt == N) {
				break;
			}
		}
		n++;
	}
}

int main() {

	int N;
	cout << "Enter the value of N : ";
	cin >> N;

	printPrimes(N); // fn to print first N prime numbers
	
	return 0;
}