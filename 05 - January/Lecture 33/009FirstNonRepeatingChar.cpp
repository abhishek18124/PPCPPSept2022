#include<iostream>
#include<queue>

using namespace std;

int main() {

	int freq[26] = {};
	queue<char> q;
	char ch;

	while(true) {

		cin >> ch;

		if(ch == '.') {
			// stream has ended
			break;
		}

		freq[ch-'a']++;
		if(freq[ch-'a']==1) {
			// ch is non-repeating
			q.push(ch);
		}
		while(!q.empty() and freq[q.front()-'a'] > 1) {
			q.pop();
		}

		q.empty() ? cout << -1 << " " : cout << q.front() << " ";

	}

	return 0;
}