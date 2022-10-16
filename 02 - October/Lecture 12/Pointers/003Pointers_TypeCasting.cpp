#include<iostream>

using namespace std;

int main() {

	char ch = 'A';
	int* ptr = (int*)&ch;
	cout << ptr << endl;
	
	int x = 10;
	char* ptr2 = (char*)&x;
	cout << ptr2 << endl;

	return 0;
}