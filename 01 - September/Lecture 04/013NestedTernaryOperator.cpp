#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cout << "enter an integer : ";
	cin >> n;

	n > 0 ? cout << "+ve" << endl : 
	n < 0 ? cout << "-ve" << endl : cout << "zero" << endl;

	return 0;
}