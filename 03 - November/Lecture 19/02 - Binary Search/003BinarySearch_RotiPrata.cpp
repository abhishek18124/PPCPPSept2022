/* 

https://www.spoj.com/problems/PRATA/

When we calculate the mid point 'm', we ask the question 

	can 'l' cooks with given ranks cook 'p' pratas in 'm' amt. of time ?
	
	now, we can rephrase this question in two ways 

	1. how many pratas can 'l' cooks cook in 'm' amt. of time ? 
	   say, 'l' cooks can cook 'x' pratas in 'm' amt. of time
	   
	   case (a)

	   now, if x >= p (initial requirement) then that means 'l' cooks 
	   can also cook 'p' pratas in 'm' amt. of time so  we get 'true' 
	   and move towards the left to minimize time
	
	   case (b)

	   if x < p then that means 'l' cooks cannot cook 'p' pratas in 'm'
	   amt. of time i.e we get false and move towards the right.

	2. how many cooks are required to cook 'p' pratas in 'm' amt. of time ?

	   the problem with asking this question is that we cannot implement it.
	   why ? because in the question we associate a rank with each cook, so
       if we were to implement this function we need know the ranks of cooks
       that we do not know.
	   
	   try to implement this function, and you'll understand the problem :)	


*/

#include<iostream>
#include<climits>

using namespace std;

int numOfPratasCookedByACook(int r, int timeLimit) {
	int count = 0; // to store the count of pratas that can be cooked in the 
			       // given timeLimit by a cook with rank 'r'
	int time = 0;  // to store the time consumed by the given cook of rank 'r'
	int n = 1;     // to store the current prata no. 

	while(true) {
		// ask the cook with rank 'r' to cook the next prata i.e. nth prata
		time += n*r;
		if(time > timeLimit) {
			break;
		}
		count++;
		n++;
	}

	return count;
}

int numOfPratasCooked(int l, int* ranks, int timeLimit) {
	int totalPratas = 0;
	for(int i=0; i<l; i++) {
		// compute no. of pratas that can be cooked by the ith cook in the given timeLimit
		totalPratas += numOfPratasCookedByACook(ranks[i], timeLimit);
	}
	return totalPratas;
}

int getMinTime(int p, int l, int* ranks) {
	int s = 0; // loose lower-bound
	int e = INT_MAX; // loose upper-bound or assign the job to the highest/top rank cook 
	int ans;
	while(s <= e) {
		int m = s+(e-s)/2;
		int x = numOfPratasCooked(l, ranks, m);
		if(x >= p) {
			// 'l' cooks can also cook 'p' pratas in 'm' units of time
			ans = m;
			// since we want to minimize the time, continue 
			// your search towards the left of 'm' i.e. the 
			// search space reduces from [s, e] to [s, m-1].
			e = m-1;
		} else {
			// 'l' cooks cannot cook 'p' pratas in 'm' units of time
			// therefore continue your search towards the right of 'm'
		 	// i.e. the search space reduces from [s, e] to [m+1, e].
		 	s = m+1;
		}
	}
	return ans;
}

int main() {

	// int t;
	// cin >> t;

	// int p, l;
	// int* ranks = new int[l];

	// while(t--) {
	// 	cin >> p >> l;
	// 	for(int i=0; i<l; i++) {
	// 		cin >> ranks[i];
	// 	}
	// 	cout << getMinTime(p, l, ranks) << endl;
	// }

	int p = 10;
	int l = 4;
	int ranks[] = {1, 2, 3, 4};

	cout << getMinTime(p, l, ranks) << endl;

	return 0;
}

