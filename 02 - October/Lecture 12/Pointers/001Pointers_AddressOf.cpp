#include<iostream>

using namespace std;

int main() {

	int x = 10;
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;

	cout << endl;

	float y = 3.14;
	cout << "y = " << y << endl;
	cout << "&y : " << &y << endl;
	cout << "sizeof(&y) = " << sizeof(&y) << "B" << endl;

	cout << endl;

	double z = 1.29;
	cout << "&z = " << &z << endl;
	cout << "sizeof(&z) = " << sizeof(&z) << "B" << endl;

	cout << endl;

	char w = 'A';
	cout << "w = " << w << endl;
	cout << "&w = " << &w << endl;
	cout << "sizeof(&w) = " << sizeof(&w) << "B" << endl;

	return 0;
}