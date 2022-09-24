#include<iostream>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};

	cout << "A[0] : " << A[0] << endl;
	cout << "A[1] : " << A[1] << endl;
	cout << "A[2] : " << A[2] << endl;
	cout << "A[3] : " << A[3] << endl;
	cout << "A[4] : " << A[4] << endl;
	// cout << "A[5] : " << A[5] << endl; // avoid this

	cout << endl;

	int B[] = {100, 200, 300, 400, 500};

	cout << "B[0] : " << B[0] << endl;
	cout << "B[1] : " << B[1] << endl;
	cout << "B[2] : " << B[2] << endl;
	cout << "B[3] : " << B[3] << endl;
	cout << "B[4] : " << B[4] << endl;

	// int C[5] = {1000, 2000, 3000, 4000, 5000, 6000};

	int D[5] = {1, 2, 3};

	cout << "D[0] : " << D[0] << endl;
	cout << "D[1] : " << D[1] << endl;
	cout << "D[2] : " << D[2] << endl;
	cout << "D[3] : " << D[3] << endl;
	cout << "D[4] : " << D[4] << endl;

	int E[5] = {}; // E is initialized with zeros

	int F[5] = {1}; 

	cout << "F[0] : " << F[0] << endl;
	cout << "F[1] : " << F[1] << endl;
	cout << "F[2] : " << F[2] << endl;
	cout << "F[3] : " << F[3] << endl;
	cout << "F[4] : " << F[4] << endl;

	
	return 0;
}