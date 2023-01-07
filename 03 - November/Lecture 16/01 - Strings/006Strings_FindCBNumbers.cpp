// constraints 1 <= n <= 17
// 49119 -> 2

#include<iostream>

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

bool isUnique(int i, int j, bool* visited) {
	for(int k=i; k<=j; k++) {
		if(visited[k] == true) {
			// kth character has been used before
			return false;
		}
	}
	return true;
}

int main() {

	string str = "49119";
	int n = str.size();

	bool visited[17] = {false};

	int count = 0;
	for(int l=1; l<=n; l++) {
		for(int i=0; i<=n-l; i++) {
			string subString = str.substr(i, l);
			int j = i+l-1;
			if(isCBNumber(subString) && isUnique(i, j, visited)) {
				count++;
				for(int k=i; k<=j; k++) {
					visited[k] = true;
				}
			}
		}
	}

	cout << count << endl;

	
	return 0;
}