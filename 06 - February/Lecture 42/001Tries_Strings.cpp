/*

Implementation of the TRIE data structure to store strings.

Motivation :

Given an array of N strings, and an array of Q queries,
check for each query if it is present in the array or not.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

class node {

	public :

		char ch;
		bool terminal;
		unordered_map<char, node*> childMap;

		node(char ch) {
			this->ch = ch;
			this->terminal = false;
		}

};

class trie {
	node* root;

	public :

		trie() {
			root = new node('\0');
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
			}
			cur->terminal = true;
		}

		bool search(string str) {
			node* cur = root;
			for(char ch : str) {
				if(cur->childMap.find(ch) == cur->childMap.end()) {
					// cur node does not have a child node with data as 'ch'
					return false;
				}
				cur = cur->childMap[ch];
			}
			return cur->terminal;
		}
};

int main() {

	string words[] = {"code", "coder", "coding", "block", "blocks", "news"};

	trie t;
	for(string word : words) {
		t.insert(word);
	}

    string queries[] = {"code", "coding", "blocked", "block", "news", "new"};

    for(string query : queries) {
    	t.search(query) ? cout << query << " is present" << endl :
    	                  cout << query << " is absent" << endl;
    }

    cout << endl;

	return 0;
}