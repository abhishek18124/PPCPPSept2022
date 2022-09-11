#include<iostream>

using namespace std;

int main() {

	int p;
	cout << "Enter the value of principle : ";
	cin >> p;

	int r;
	cout << "Enter the value of rate :" ;
	cin >> r;

	int t;
	cout << "Enter the value of time : ";
	cin >> t;

	float si = p*r*t/100.0;

	cout << "Simple Interest : " << (p*r*t)/100 << endl;
	cout << "Simple Interest : " << (p*r*t)/100.0 << endl;
	cout << "Simple Interest : " << (p*r*t*1.0)/100 << endl;
	cout << "Simple Interest : " << (p*r*t)/(float)100 << endl;
	cout << "Simple Interest : " << (float)(p*r*t)/100 << endl;
	cout << "Simple Interest : " << si << endl;
	
	return 0;
}




