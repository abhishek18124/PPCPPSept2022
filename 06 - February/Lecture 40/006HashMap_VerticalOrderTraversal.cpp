/*

	given the pre-order traversal of a binary tree, output its vertical order traversal.

	Example 
		Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
		Output: 40
		        20 70
		        10 50
		        30
		        60
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

TreeNode* buildTree() {
	int x;
	cin >> x;

	if(x == -1) {
		TreeNode* root = NULL;
		// root represents an empty tree
		return root;
	}

	TreeNode* root = new TreeNode(x);
	root->left = buildTree();
	root->right= buildTree();

	return root;
}

void verticalOrder(TreeNode* root, map<int, vector<int>>& distMap, int d) {

	if(!root) {
		return;
	}

	distMap[d].push_back(root->val);
	verticalOrder(root->left, distMap, d-1);
	verticalOrder(root->right, distMap, d+1);

}

int main() {

	TreeNode* root = NULL;
	root = buildTree();

	map<int, vector<int>> distMap;

	verticalOrder(root, distMap, 0);

	for(pair<int, vector<int>> p : distMap) {
		cout << p.first << " : ";
		for(int node : p.second) {
			cout << node << " ";
		}
		cout << endl;
	}


	return 0;
}

