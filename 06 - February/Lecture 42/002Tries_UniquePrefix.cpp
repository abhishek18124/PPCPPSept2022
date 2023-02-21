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
				cur->freq++;
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

		string uniquePrefix(string str) {
			node* cur = root;
			string prefix = "";
			for(char ch : str) {
				cur = cur->childMap[ch];
				prefix += ch;
				if(cur->freq == 1) {
					// current is not shared any other string, you've found a unique prefix
					return prefix;
				}
			}

			// str does not have a unique prefix
			return "";
		}
};


int main() {

	string words[] = {"code", "coder", "coding", "new", "neon"};

	trie t;
	for(string word : words) {
		t.insert(word);
	}

	for(string word : words) {
		cout << "uniquePrefix(" << word << ") = " << t.uniquePrefix(word) << endl;
	}

	return 0;
}