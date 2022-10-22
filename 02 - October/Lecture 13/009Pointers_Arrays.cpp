#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int* ptr = arr; // or &arr[0]

	for(int i=0; i<n; i++) {
		cout << arr[i] << " " << *(arr+i) << " " << ptr[i] << " " << *(ptr+i) << " " << &arr[i] << " " << (arr+i) << endl;
	}

	// arr++;
	ptr++;// ptr=ptr+1= ptr+1.sizeof(int)

	cout << *ptr << endl;

	return 0;
}