#include<iostream>

using namespace std;

int main() {

	int arr[3][4];

	cout << "arr   = " << arr   << " arr[0] = " << arr[0] << endl;
	cout << "arr+1 = " << arr+1 << " arr[1] = " << arr[1] << endl;
	cout << "arr+2 = " << arr+2 << " arr[2] = " << arr[2] << endl;

	int(* ptr)[4] = arr;

	int (*ptr2)[4] = arr+1;

	return 0;
}