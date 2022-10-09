// contraints : m <= 10 and n <= 10

#include<iostream>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int arr[20];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int brr[10];
	for(int i=0; i<m; i++) {
		cin >> brr[i];
	}

	int i=n-1;
	int j=m-1;
	int k=n+m-1;

	while(i >= 0 && j >= 0) {
		if(arr[i] > brr[j]) {
			arr[k] = arr[i];
			i--;
			k--;
		} else {
			arr[k] = brr[j];
			j--;
			k--;
		}
	}

	while(j >= 0) { // you've exhaused the first array i.e. arr[0...n-1]
		arr[k] = brr[j];
		j--;
		k--;
	}

	for(int l=0; l<n+m; l++) {
		cout << arr[l] << " ";
	}

	cout << endl;

	return 0;
	
}