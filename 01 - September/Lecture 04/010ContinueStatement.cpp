#include<iostream>
#include<climits>

using namespace std;

int main() {

	int i = 0;

	while(i < 5) {
		i = i+1;
		if(i == 2) {
			continue;
		}
		cout << i << " ";
	}

	return 0;
}