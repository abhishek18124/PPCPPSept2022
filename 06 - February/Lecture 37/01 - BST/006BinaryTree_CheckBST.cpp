/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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


bool isBST(TreeNode* root, long long lb, long long ub) {

	// base case
	if(!root) { // root == true
		// tree is empty
		return true;
	}

	// recursive case

	return root->val > lb and root->val < ub  &&
           isBST(root->left, lb, root->val)   &&
	       isBST(root->right, root->val, ub) ;

}

int main() {

	TreeNode* root = new TreeNode(10);
	
	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	long long lb = (long long)INT_MIN-1;
	long long ub = (long long)INT_MAX+1;

	// LLONG_MIN -> -2^63
	// LLONG_MAX -> 2^63-1

	isBST(root, lb, ub) ? cout << "true" << endl :
	                      cout << "false" << endl;

	return 0;
}