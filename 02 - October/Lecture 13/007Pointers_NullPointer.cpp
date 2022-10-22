#include<iostream>

using namespace std;

int main() {

	int* p = nullptr;
	int* q = NULL; // preferred way for this course
	int* r = 0;

	// null pointers are equal
	if(p == q && q == r) {
		cout << "all p, q, r store the null address" << endl;
	}

	// you cannot derefernce a null pointers

	// cout << *p << endl;
	
	return 0;
}