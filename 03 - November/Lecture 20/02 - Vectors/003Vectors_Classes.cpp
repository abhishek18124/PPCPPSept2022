#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name; 
	int age;
	char gender;
	double credits;
	
	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}	
};

/* 
	return 'true' when a swap isn't required.

*/

bool myComparator(customer c1, customer c2) {
	// todo ...
}

int main() {

	vector<customer> v;

	return 0;
}