#include<iostream>

using namespace std;

class customer {

	public :

		string name;
		int age;
		char gender;
		double credits;
		
		customer(string n, int a, char g, double c) : name(n), age(a), gender(g), credits(c)  {
			cout << "\ninside parameterised constructor of \'customer\' class\n";
			// name = n;
			// age = a;
			// gender = g;
			// credits = c;
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

	customer c("eren", 19, 'M', 100);

	c.printCustomerInfo();
		
	return 0;
}