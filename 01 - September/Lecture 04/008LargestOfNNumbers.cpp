#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	int lsf = INT_MIN; // to track the "largest so far"

	int i = 0;
	while(i < n) {
		int data;
		cin >> data;

		if(data > lsf) {
			lsf = data;
		}
		i = i+1;
	}

	cout << lsf << endl;
	
	return 0;
}