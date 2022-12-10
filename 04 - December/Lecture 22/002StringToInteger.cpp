#include<iostream>

using namespace std;

int f(string str, int n) {

	// base case
	if(n == 1) {
		// length of the string is 1, convert it into an integer
		return str[0]-'0';
	}

	// recursive case

	// 1. extract the subString that contains the first (n-1) characters
	string subString = str.substr(0, n-1);
	int A = f(subString, n-1);

	char ch = str[n-1];
	return A*10 + (ch-'0');

}

int main() {

	string str = "1234";
	int n = str.size();

	int x = f(str, n);

	cout << x << endl;

	return 0;
}