#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 42;

	int count = 0; // to track the no. of set bits in 'n'

	// for(int k=0; k<=31; k++) { // 0 to < ceil(log2(n+1))

	// 	// check if the kth bit of 'n' is set 

	// 	if((n>>k)&1) { // or (1<<k)&n
	// 		count++;
	// 	}

	// }

	for(int k=0; k<ceil(log2(n+1)); k++) { 

		// check if the kth bit of 'n' is set 

		if((n>>k)&1) { // or (1<<k)&n
			count++;
		}

	}

	cout << "number of set bits : " << count << endl;
	
	return 0;
}