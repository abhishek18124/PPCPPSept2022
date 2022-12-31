#include<iostream>
#include<vector>

using namespace std;

int n = 11;
vector<int> primes;

void generateSieve() {

	vector<int> sieve(n+1, 1);

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
			// 'i' is a prime no.
			primes.push_back(i);
		}
	}
}

void segmentedSieve(int lb, int ub) {

	vector<int> segment(ub-lb+1, 1);

	for(int i=0; i < primes.size() && primes[i]*primes[i] <= ub; i++) {
	// for(int i=0; i<primes.size(); i++) {
		int p = primes[i];
		// mark all the multiples of 'p' in the segment as non-primes
		int start = (lb/p) * p;
		if(start < lb) {
			start = start + p;
		}
		for(int j=start; j<=ub; j+=p) {
			segment[j-lb] = 0;
		}

		if(start == p) {
			segment[start-lb] = 1;
		}
	}

	for(int i=lb; i<=ub; i++) {
		if(segment[i-lb] == 1) {
			cout << i << " ";
		}
	}

}

int main() {

	generateSieve();

	// for(int i=0; i<primes.size(); i++) {
	// 	cout << primes[i] << " ";
	// }

	// find all the prime nos. in the range [100, 200]

	int lb = 5;
	int ub = 100;

	segmentedSieve(lb, ub);

	return 0;
}