// strlen <= 100 

#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter the no. of strings : ";
	cin >> n;

	char inp[101]; // to read user input
	char lsf[101]; // to track the string which is largest so far
	
	cin >> inp;
	strcpy(lsf, inp);

	for(int i=1; i<=n-1; i++) {

		cin >> inp;
		if(strcmp(inp, lsf) > 0) {
			// inp is greater than lsf
			strcpy(lsf, inp);
		}

	}

	cout << lsf << endl;	

	return 0;
}
