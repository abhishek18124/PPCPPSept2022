#include<iostream>

using namespace std;

class customer {
	public :
		char* name;
		int age;
		char gender;
		double credits;

		customer() {

		}

		customer(char* n, int a, char g, double c) {
			cout << "I am inside the parameterised constructor of the customer class" << endl;
			name = new char[100];
			strcpy(name, n);
			age = a;
			gender = g;
			credits = c;
		}

		customer(customer& c) {
			cout << "I am inside the copy constructor of the customer class" << endl;
			name = new char[100];
			strcpy(name, c.name);
			age = c.age;
			gender = c.gender;
			credits = c.credits;
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

	customer c1("naruto", 32, 'M', 5000);

	customer c2 = c1; // copy constructor

	strcpy(c2.name, "sakura");

	cout << c1.name << endl << c2.name << endl;

	// c2.age = 21;

	// c2.gender = 'F';

	// c2.credits = 100;

	// // c2.printCustomerInfo();
	
	// cout << c2.name << endl;

	// cout << c1.name << endl;

	// cout << c2.age << endl;

	// cout << c1.age << endl;

	// cout << c2.gender << endl;
	
	// cout << c1.gender << endl;

	// cout << c2.credits << endl;

	// cout << c1.credits << endl;

	return 0;
}