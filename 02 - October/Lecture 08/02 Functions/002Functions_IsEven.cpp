#include<iostream>

using namespace std;

void isEven(int n) {
	if(n%2 == 0) {
		cout << n << " is even" << endl; 
	} else {
		cout << n << " is odd" << endl;
	}
	return; // optional
}

int main() {

	isEven(2);
	isEven(3);
	
	return 0;
}