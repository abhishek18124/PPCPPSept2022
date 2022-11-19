#include<iostream>

using namespace std;

class creditCard {

	public :

		string cardNumber;
		string bankName;

		creditCard()  {
			cout << "\ninside default constructor of \'creditCard\' class\n";
		}

		creditCard(string cn, string bn)  {
			cout << "\ninside parameterised constructor of \'creditCard\' class\n";
			cardNumber = cn;
			bankName = bn;
		}		

};

class customer {

	public :

		string name;
		int age;
		char gender;
		double credits;
		creditCard card;
		
		customer(string n, int a, char g, double c, string cn, string bn) : card(cn, bn) {
			cout << "\ninside parameterised constructor of \'customer\' class\n";
			name = n;
			age = a;
			gender = g;
			credits = c;
			// card.cardNumber = cn;
			// card.bankName = bn;
		}

		void printCustomerInfo() {
			cout << "\nCustomer Information\n";
			cout << "Name : " << name << endl;
			cout << "Age : " << age << endl;
			cout << "Gender : " << gender << endl;
			cout << "Credits : " << credits << endl;
			cout << "CardNumber : " << card.cardNumber << endl;
			cout << "BankName : " << card.bankName << endl;
		}

};

int main() {

	customer c("eren", 19, 'M', 100, "1234", "HDFC");

	c.printCustomerInfo();
		
	return 0;
}