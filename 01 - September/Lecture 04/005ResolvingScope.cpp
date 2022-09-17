#include<iostream>

using namespace std;

int x = 100;

int main() {

	cout << x << endl;

	int x = 10;

	int y = 40;

	cout << x <<  " "  << y << endl;

	{

		cout << y << endl;

		int x = 30;

		int y = 20;

		cout << x << " " << y << endl;
		
	}

	cout << y << endl;
	
	return 0;
}