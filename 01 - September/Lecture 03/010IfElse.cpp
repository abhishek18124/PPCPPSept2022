#include<iostream>

using namespace std;

int main() {

	int age;

	cout << "Enter your age  : ";

	cin >> age;

	if(age >= 18) {
		cout << "you are eligible to vote!" << endl;
	} else {
		cout << "you are not eligible to vote" << endl;
	}

	cout << "You are outside the body of if-block" << endl;

	return 0;
}