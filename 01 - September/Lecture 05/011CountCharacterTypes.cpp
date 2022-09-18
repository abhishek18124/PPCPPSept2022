#include<iostream>

using namespace std;

int main() {

	int lCount = 0; // to track the no. of lowercase letters 
	int uCount = 0; // to track the no. of uppercase letters
	int dCount = 0; // to track the no. of digits
	int sCount = 0; // to track the no. of speical symbols
	int wCount = 0; // to track the no. of whitespaces

	char ch;

	while(true) {

		ch = cin.get();

		if(ch == '$') {
			break;
		}

		if(ch >= 'A' and ch <= 'Z') {
			uCount++;
		} else if(ch >= 'a' and ch <= 'z') {
			lCount++;
		} else if(ch >= '0' and ch <= '9') {
			dCount++;
		} else if(ch == ' ' || ch == '\n' || ch == '\t') {
			wCount++;
		} else {
			sCount++;
		}

	}

	cout << "lowerCase : " << lCount << endl;
	cout << "upperCase : " << uCount << endl;
	cout << "digitCount : " << dCount << endl;
	cout << "whiteSpaceCount : " << wCount << endl;
	cout << "specialCount : " << sCount << endl;
	
	return 0;
}