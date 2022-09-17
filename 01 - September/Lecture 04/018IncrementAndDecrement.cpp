#include<iostream>

using namespace std;

int main() {

	int x = 0;

	x++; // or ++x

	cout << "x : " << x << endl;

	cout << x++ << endl; // 1

	cout << ++x << endl; // 3

	int y = 1;

	y--; // or --y

	cout << "y : " << y << endl;

	cout << --y << endl; // -1

	cout << y-- << endl; // -1

	cout << y << endl; // -2
	
	return 0;
}