#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n = 100;

	vector<int> sieve(101, 1);

	sieve[0] = 0;
	sieve[1] = 0;

	// for(int i=2; i<=n; i++) {
	// 	if(sieve[i] == 1) {
	// 		// i is a prime no. , mark all the multiples of 'i' as non-primes
	// 		for(int j=2*i; j<=n; j += i) {
	// 			sieve[j] = 0;
	// 		}
	// 	}
	// }

	// for(int i=2; i<=n; i++) {
	// 	if(sieve[i] == 1) {
	// 		// i is a prime no. , mark all the multiples of 'i' as non-primes
	// 		for(int j=i*i; j<=n; j += i) {
	// 			sieve[j] = 0;
	// 		}
	// 	}
	// }

	for(int i=2; i*i<=n; i++) {
		if(sieve[i] == 1) {
			// i is a prime no. , mark all the multiples of 'i' as non-primes
			for(int j=i*i; j<=n; j += i) {
				sieve[j] = 0;
			}
		}
	}


	for(int i=2; i<=n; i++) {
		if(sieve[i] == 1) {
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}