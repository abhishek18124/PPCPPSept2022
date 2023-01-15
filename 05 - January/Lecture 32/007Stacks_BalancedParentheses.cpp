#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(string str) {
	stack<char> s;
	for(char ch : str) {
		switch(ch) {
			case '(' : 
			case '[' :
			case '{' : s.push(ch); break;
			case ')' : if(!s.empty() && s.top() == '(') s.pop(); else return false; break;
			case ']' : if(!s.empty() && s.top() == '[') s.pop(); else return false; break;
		    case '}' : if(!s.empty() && s.top() == '{') s.pop(); else return false; break;
		}
	}

	// if(s.empty()) {
	// 	// input string is valid
	// 	return true;
	// } else {
	// 	return false;
	// }

	return s.empty();
}

int main() {

	string str = "]([{}])";

	isBalanced(str) ? cout << "balanced!" << endl :
	                  cout << "not balanced!" << endl;

	return 0;
}