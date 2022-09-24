#include<iostream>

using namespace std;

int main() {

	int arr[5]; // array declaration

	cout << "sizeof(arr) : " << sizeof(arr) << "B" << endl;

	// by default, when we declare an array, it contain garbage values

	cout << "arr[0] : " << arr[0] << endl;
	cout << "arr[1] : " << arr[1] << endl;

	return 0;
}