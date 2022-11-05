#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 23, 29};

bool isCBNumber(string str) {

	long long num = stoll(str);

	if(num == 0 || num == 1) {
		// str is not a CB number
		return false;
	}

	for(int i=0; i<9; i++) {
		if(num == primes[i]) {
			// str is a CB number
			return true;
		}
 	}

 	for(int i=0; i<9; i++) {
 		if(num%primes[i] == 0) {
 			// str is not a CB number
 			return false;
 		}
 	}

 	return true;

}

int main() {

	string str = "998";
	
	isCBNumber(str) ? cout << str  << " is a CB Number" << endl :
	                  cout << str << " is not a CB Number" << endl;
	
	return 0;
}