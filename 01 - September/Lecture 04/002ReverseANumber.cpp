#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive interger : ";
	cin >> n;

	int rev = 0; // to store the reverse of 'n'

	while(n > 0) {
		int digit = n%10;
		rev = rev*10 + digit;
		n = n/10;
	}

	cout << "reversed number : " << rev << endl;
	
	return 0;
}