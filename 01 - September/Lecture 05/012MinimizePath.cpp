#include<iostream>

using namespace std;

int main() {

	int x = 0; // to track the net movement along the x-axis
	int y = 0; // to track the net movement along the y-axis

	char ch;

	while(true) {

		ch = cin.get();

		if(ch == '\n') {
			break;
		}

		if(ch == 'E') {
			x++;
		} else if(ch == 'W') {
			x--;
		} else if(ch == 'N') {
			y++;
		} else {
			y--;
		}

	}

	// cout << "(" << x << ", " << y << ")" << endl;

	if(x >= 0 and y >= 0) {

		// 1st quadrant

		// print 'E' x times
		for(int i=1; i<=x; i++) {
			cout << 'E';
		}

		// print 'N' y times
		for(int i=1; i<=y; i++) {
			cout << 'N';
		}

	} else if(x < 0 and y >= 0) {

		// 2nd quadrant

		// print 'N' y times
		for(int i=1; i<=y; i++) {
			cout << 'N';
		}

		// print 'W' -x times
		for(int i=1; i<=-x; i++) {
			cout << 'W';
		}

	} else if (x < 0 and y < 0) {

		// 3rd quadrant

		// print 'S' -y times
		for(int i=1; i<=-y; i++) {
			cout << 'S';
		}

		// print 'W' -x times
		for(int i=1; i<=-x; i++) {
			cout << 'W';
		}

	} else {

		// 4th quadrant

		// print 'E' x times
		for(int i=1; i<=x; i++) {
			cout << 'E';
		}

		// print 'S' -y times
		for(int i=1; i<=-y; i++) {
			cout << 'S';
		}
	}

	cout << endl;
	
	return 0;
}