/*

given the pre-order traversal of a binary tree, design a recursive algorithm to 
compute its height
	 
	  height of a binary tree is equal to the height of the root TreeNode which is 
	  equal to the length of the longest path from the root TreeNode to a leaf TreeNode.

Example : Input  :10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output :3

*/


#include<iostream>

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

	int val;
	cin >> val;

	// base case

	if(val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();
	
	return root;

}

int computeHeight(TreeNode* root) {

	// base case
	if(root == NULL) {
		// tree empty
		return -1;
	}

	// recursive case

	// 1. compute the height of the leftSubtree
	int hL = computeHeight(root->left);

	// 2. compute the height of the rightSubtree
	int hR = computeHeight(root->right);

	return 1 + max(hL, hR);

}

int main() {

	TreeNode* root = buildTree();

	cout << computeHeight(root) << endl;

	return 0;
}