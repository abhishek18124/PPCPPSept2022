#include<iostream>

using namespace std;

string f(string str) {
	// base case
	if(str == "") { // or str.empty()
		// str is empty
		return str;
	}

	// recursive case

	string temp(1, str[0]);

	string subString = str.substr(1);

	// 1. ask your friend to move all the 'x' characters to the end of the given subString
	string subStringFromMyFriend = f(subString);

	if(temp == "x") {
		return subStringFromMyFriend + temp;
	} 
		
	return temp + subStringFromMyFriend;
	

}

int main() {

	string str = "bxayaxxxb";

	// abcxxx

	cout << f(str) << endl;

	return 0;
}