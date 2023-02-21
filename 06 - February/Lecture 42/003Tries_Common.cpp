#include<iostream>
#include<unordered_map>

using namespace std;

class node {

	public :

		char ch;
		bool terminal;
		unordered_map<char, node*> childMap;
		int freq;

		node(char ch) {
			this->ch = ch;
			this->terminal = false;
			this->freq = 0;
		}

};

class trie {
	node* root;
	int n; // to track no. of words in the trie

	public :

		trie() {
			root = new node('\0');
			n = 0;
		}

		void insert(string str) {
			node* cur = root;
			for(char ch : str) {
				if(cur->childMap.find(ch) == cur->childMap.end()) {
					// current node does not have a child node with the data as 'ch'
					node* n = new node(ch);
					cur->childMap[ch] = n;
				}
				cur = cur->childMap[ch];
				cur->freq++;
			}
			cur->terminal = true;
			n++;
		}

		// string longestCommonPrefix() {
		// 	node* cur = root;
		// 	string prefix = "";
		// 	while(cur->childMap.size() > 0) {
		// 		cur = cur->childMap.begin()->second;
		// 		if(cur->freq != n) break;
		// 		prefix += cur->ch;
		// 	}
		// 	return prefix;
		// }

		string longestCommonPrefix(string str) {
			node* cur = root;
			string prefix = "";
			for(char ch : str) {
				cur = cur->childMap[ch];
				if(cur->freq != n) break;
				prefix += ch;
			}
			return prefix;
		}


};



int main() {

	string words[] = {"flow", "floor", "fly"};

	trie t;
	for(string word : words) {
		t.insert(word);
	}

	// cout << t.longestCommonPrefix() << endl;

	cout << t.longestCommonPrefix(words[0]) << endl;

	return 0;
}