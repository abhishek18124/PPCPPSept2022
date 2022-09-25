// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

int main() {

	// int arr[100];

	// int n;
	// cout << "enter the value of n : ";
	// cin >> n;

	// // read 'n' integers into the array

	// for(int i=0; i<n; i++) {
	// 	cin >> arr[i];
	// }

	// int fL = INT_MIN; // to track the first  largest so far
	// int sL = INT_MIN; // to track the second largest so far
	// int tL = INT_MIN; // to track the third  largest so far

	// int fS = INT_MAX; // to track the first  smallest so far
	// int sS = INT_MAX; // to track the second smallest so far

	// for(int i=0; i<n; i++) {

	// 	if(arr[i] > fL) {
	// 		tL = sL;
	// 		sL = fL;
	// 		fL = arr[i];
	// 	} else if(arr[i] > sL) {
	// 		tL = sL;
	// 		sL = arr[i];
	// 	} else if(arr[i] > tL) {
	// 		tL = arr[i];
	// 	}

	// 	if(arr[i] < fS) {
	// 		sS = fS;
	// 		fS = arr[i];
	// 	} else if(arr[i] < sS) {
	// 		sS = arr[i];
	// 	}

	// }

	// int p1 = fL*sL*tL;
	// int p2 = fL*fS*sS;

	// cout << max(p1, p2) << endl;

	cout << max(2, max(3, max(4, 5))) << endl;
	cout << max({2, 3, 4, 5}) << endl;


	cout << min(2, min(3, min(4, 5))) << endl;
	cout << min({2, 3, 4, 5}) << endl;


	return 0;
}




