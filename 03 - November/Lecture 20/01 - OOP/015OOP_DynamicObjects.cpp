#include<iostream>

using namespace std;

class customer {

	public :

		string name;
		int age;
		char gender;
		double credits;

		customer() {
			cout << "\ninside default constructor of \'customer\' class\n";
		}

		customer(string n, int a, char g, double c) {
			cout << "\ninside parameterised constructor of \'customer\' class\n";
			name = n;
			age = a;
			gender = g;
			credits = c;
		}

		void printCustomerInfo() {
			cout << "\nCustomer Information\n";
			cout << "Name : " << name << endl;
			cout << "Age : " << age << endl;
			cout << "Gender : " << gender << endl;
			cout << "Credits : " << credits << endl;
		}

};


int main() {

	// customer* cptr1 = new customer;

	// cptr1->name = "reiner";
	// cptr1->age = 27;
	// cptr1->gender = 'T';
	// cptr1->credits = 1000;


	// cptr1->printCustomerInfo();

	customer* cptr2 = new customer("armin", 19, 'M', 200);

	cptr2->printCustomerInfo();

	return 0;
}