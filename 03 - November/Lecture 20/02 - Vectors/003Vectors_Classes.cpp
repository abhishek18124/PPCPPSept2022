#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

	double credits;

public:

	string name; 
	int age;
	char gender;
	
	
	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}	


	double getCredits() {
		return credits;
	}
};

/* 
	return 'true' when a swap isn't required.

*/

bool myComparator(customer c1, customer c2) {
	// if(c1.age < c2.age) {
	// 	// swap is not required
	// 	return true;
	// } else {
	// 	// swap is required
	// 	return false;
	// }

	// return c1.age < c2.age; // sorting based on age in the inc. order

	// return c1.credits > c2.credits; // sorting based on credits in the dec. order

	return c1.getCredits() > c2.getCredits();
}

int main() {

	vector<customer> v;

	// customer c("ankit", 22, 'M', 100);
	// v.push_back(c);

	v.push_back(customer("ankit", 22, 'M', 100));
	v.push_back(customer("pradeep", 21, 'M', 500));
	v.push_back(customer("garveet", 19, 'M', 2000));
	v.push_back(customer("paras", 20, 'M', 300));
	v.push_back(customer("tanishka", 18, 'F', 400));

	sort(v.begin(), v.end(), myComparator);

	for(customer c : v) {
		cout << c.name << " : " << c.getCredits() << endl;
	}

	return 0;
}

