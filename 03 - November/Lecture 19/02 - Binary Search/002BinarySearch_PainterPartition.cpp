/*

https://hack.codingblocks.com/app/contests/3122/1057/problem

When we calculate the mid point 'm', we ask the question 

	can 'k' painters paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	now, we can rephrase this question in two ways 

	1. how many painters are required to paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	   say, 'x' painters can paint 'n' boards of given 'len' in 'm' amt. of time then
	   
	   case (a)

	   now, if x <= k then that means 'k' painters can also paint 'n' boards of given 'len' 
	   in 'm' amt. of time so we get 'true' and move towards the left to minimize time
	
	   case (b)

	   if x > k then that means 'k' painters cannot paint 'n' boards of given 'len' in 'm'
	   amt. of time i.e we get false and move towards the right.

    2. how many boards of given 'len' can 'k' painters paint in 'm' amt. of time ? 

*/

#include<iostream>
#include<climits>

using namespace std;

int numPaintersRequired(int n, int* b, int timeLimit) {
	int numPainters = 1;
	int time = 0;
	int i = 0;
	while(i < n) {
		// paint the ith board
		time += b[i];

		if(time > timeLimit) {
			// add a new painter to the job
			numPainters++;
			time = 0; // reset the time, since painters work in parallel and share the same clock
			continue;
		}

		i++;
	}

	return numPainters;
}


int getMinTime(int k, int n, int*b) {
	int s = INT_MIN; // for the tightest lower-bound, assign a painter to each board
	int e = 0;       // for the tightest upper-bound, assign a single painter to paint all the boards
	for(int i=0; i<n; i++) {
		s = max(s, b[i]);
		e += b[i];
	}  
	int ans;

	while(s <= e) {
		int m = s + (e-s)/2;
		int x = numPaintersRequired(n, b, m);
		if(x <= k) {
			// 'k' painters can also paint 'n' boards in 'm' amt. of time
			ans = m;
			// since we want to minimize the time, continue 
			// your search towards the left of 'm' i.e. the 
			// search space reduces from [s, e] to [s, m-1].
			e = m-1;
		} else {
		 	// 'k' painters cannot paint 'n' boards in 'm' amt. of time
		 	// therefore continue your search towards the right of 'm'
		 	// i.e. the search space reduces from [s, e] to [m+1, e].
		 	s = m+1;
		}
	}

	return ans;
}

int main() {

	// int k;
	// cin >> k;

	// int n;
	// cin >> n;

	// int* b = new int[n];
	// for(int i=0; i<n; i++) {
	// 	cin >> b[i];
	// }

	// cout << getMinTime(k, n, b) << endl;

	int k = 3;
	int n = 5;
	int b[] = {1, 3, 5, 2, 4};

	cout << getMinTime(k, n, b) << endl;

	return 0;
}