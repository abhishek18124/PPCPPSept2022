/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>
#define ll long long

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

int findMaximum(TreeNode* root) {
	if(root == NULL) {
		// tree is empty
		return INT_MIN;

	}

	while(root->right != NULL) {
		root = root->right;
	}
	return root->val;
}

int findMinimum(TreeNode* root) {
	if(root == NULL) {
		// tree is empty
		return INT_MAX;
	}

	while(root->left != NULL) {
		root = root->left;
	}
	return root->val;
}

// bool validateBST(TreeNode* root) {

// 	// base case
// 	if(!root) {
// 		// tree is empty therefore it is a BST
// 		return true;
// 	}

// 	// recursive case

// 	// 1. check if the leftSubtree is a BST
// 	bool X = validateBST(root->left);

// 	// 2. check if the rightSubtree is a BST
// 	bool Y = validateBST(root->right);

// 	// 3. check if the BST property is satisfied at the root node
// 	bool Z = root->val > findMaximum(root->left) && root->val < findMinimum(root->right) ? true : false;

// 	return X && Y && Z;

// }

class Triple {

	public :

	bool isBST;
	ll minimum;
	ll maximum;

};

Triple validateBSTEfficient(TreeNode* root) {

	Triple t;

	// base case
	if(!root) {
		// tree is empty therefore it is a BST
		t.isBST = true;
		t.maximum = (ll)INT_MIN-1;
		t.minimum = (ll)INT_MAX+1;
		return t;
	}

	// recursive case

	// 1. check if the leftSubtree is a BST and simulataneously find its minimum and maximum
	Triple tL = validateBSTEfficient(root->left);

	// 2. check if the rightSubtree is a BST and simulataneously find its minimum and maximum
	Triple tR = validateBSTEfficient(root->right);

	// 3. check if the BST property is satisfied at the root node
	bool Z = root->val > tL.maximum && root->val < tR.minimum ? true : false;

	t.isBST = tL.isBST && tR.isBST && Z;
	t.minimum = min(tL.minimum, min(tR.minimum, (ll)root->val));
	t.maximum = max(tL.maximum, max(tR.maximum, (ll)root->val));

	return t;

}


int main() {

	TreeNode* root = new TreeNode(10);
	
	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(1);

	// validateBST(root) ? cout << "true" << endl :
	// 			  cout << "false" << endl;

	validateBSTEfficient(root).isBST ? cout << "true" << endl :
				                       cout << "false" << endl;

	return 0;
}