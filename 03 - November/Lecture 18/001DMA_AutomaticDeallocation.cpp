#include<iostream>

using namespace std;

int y = 500;

int* f() {
	// int x = 10;
	// return &x;

	int* ptr = new int;
	return ptr;

}

int main() {

	int* xptr = f();

	return 0;
}