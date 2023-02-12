#include<iostream>
#include<vector>

using namespace std;

int findDuplicate(vector<int> v) {

	int slow = v[0];
	int fast = v[0];

	while(true) {
		slow = v[slow];
		fast = v[v[fast]];
		if(slow == fast) {
			break;
		}
	}

	slow = v[0];
	while(slow != fast) {
		slow = v[slow];
		fast = v[fast];
	}

	return slow; // or fast

}

int main() {

	vector<int> v = {1, 3, 4, 2, 2};

	cout << findDuplicate(v) << endl;
	
	return 0;
}