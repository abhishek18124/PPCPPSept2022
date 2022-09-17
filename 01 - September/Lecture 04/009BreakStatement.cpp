#include<iostream>
#include<climits>

using namespace std;

int main() {

	int count = 0; // to track the count of non-negative nos.
	int data;

	while(true) {
		cin >> data;
		if(data < 0) {
			break;
		}
		count = count+1;
	}

	cout << "count = " << count << endl;
	
	return 0;
}