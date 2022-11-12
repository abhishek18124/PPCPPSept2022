#include<iostream>

using namespace std;

int* resize(int* A, int c) {
	cout << "resizing from " 
	     << c*sizeof(int) << "B to " 
	     << 2*c*sizeof(int) << "B" << endl; 

	int* B = new int[2*c];
	for(int i=0; i<c; i++) {
		B[i] = A[i];
	}
	delete [] A;
	return B;
	
}

int main() {

	int* A = new int[1];
	int c = 1; // to store the maximum capacity of the dynamic array
	int i = 0; // to store the size of the dynamic array

	int x; // to store the integer value read from the user

	while(true) {

		cout << ">> ";
		cin >> x;

		if(x < 0) {
			break;
		}

		if(i == c) {
			// you've exhaused the capacity of the dynamic array
			A = resize(A, c);
			c = c*2;
		}

		A[i] = x;
		i++;

	}

	// print the dynamic array 

	for(int j=0; j<i; j++) {
		cout << A[j] << " ";
	}

	cout << endl;

	return 0;

}