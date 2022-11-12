#include<iostream>

using namespace std;

int main() {

	// int x = 100;

	// x = 200;

	int* ptr = new int;

	*ptr = 10;

	(*ptr)++;

	cout << *ptr << endl;

	delete ptr; // to avoid memory leak

	ptr = new int;

	*ptr = 50;

	cout << *ptr << endl;

	delete ptr;

	return 0;
}