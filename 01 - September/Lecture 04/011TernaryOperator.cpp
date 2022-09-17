#include<iostream>
#include<climits>

using namespace std;

int main() {

	int marks;
	cout << "enter your marks : ";
	cin >> marks;

	marks > 40 ? cout << "pass" << endl : 
	             cout << "fail" << endl ;
	
	return 0;
}