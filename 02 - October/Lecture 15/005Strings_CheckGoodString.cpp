#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	// for(int i=0; i<str.size(); i++) {
	// 	char ch = str[i];
	// 	if(!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
	// 		// ch is a consonant
	// 		return false;
	// 	}
	// }

	for(char ch : str) {
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			// ch is a vowel
		} else {
			// ch is a consonant
			return false;
		}
	}

	// str is a good string

	return true;

}

int main() {

	string str = "uoxea";
	
	isGoodString(str) ? cout << str << " is a good string" << endl :
	                    cout << str << " is not a good string" << endl;
	
	return 0;
}