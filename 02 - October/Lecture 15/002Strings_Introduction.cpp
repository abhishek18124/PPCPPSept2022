#include<iostream>

using namespace std;

int main() {

	// // declaring a string 
	// string str;

	// // assigning a string literal 
	// str = "coding blocks";

	// // printing a string

	// cout << str << endl;

	// for(int i=0; str[i] != '\0'; i++) {
	// 	cout << str[i] << " ";
	// }

	// cout << endl;
	
	// // indexing into a string

	// cout << str[0] << endl;
	// cout << str[1] << endl;

	// // initialising a string

	// string str2 = "new delhi";

	// cout << str2 << endl;

	// // creating a copy of string

	// string str3 = str2; // string str3(str2); // copy constructor

	// string str4;

	// str4 = str2; // copy assignment operator

	// cout << str3 << " " << str4 << endl;

	// reading input into a string

	// 1. using cin >> 

	string str5;

	// cin >> str5;

	// cout << str5;

	// 2. using getline

	getline(cin, str5); // '\n' is the default delimiting char.

	cout << str5 << endl;
	
	return 0;
}