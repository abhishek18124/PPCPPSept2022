/*

given the pre-order traversal of a binary tree, design a recursive 
algorithm to mirror it.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 10 30 60 -1 -1 -1 20 50 -1 70 -1 -1 40 -1 -1
                  
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


void printPreOrder(TreeNode* root) {

	// base case
	if(!root) { // root == NULL
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. process the root TreeNode
	cout << root->val << " ";

	// 2. do the preOrder traversal of the leftSubtree
	printPreOrder(root->left);

	// 3. do the preOrder traversal of the rightSubtree
	printPreOrder(root->right);

}

TreeNode* mirrorTree(TreeNode* root) {

	// base case
	if(!root) { // root == NULL
		return root;
	}

	// recursive case

	// 1. mirror the leftSubtree
	root->left = mirrorTree(root->left);

	// 2. mirror the rightSubtree
	root->right = mirrorTree(root->right);

	// 3. swap the leftSubtree (leftChild) with the rightSubtree (rightChild)
	swap(root->left, root->right);

	return root;

}

int main() {

	TreeNode* root = buildTree();
	root = mirrorTree(root);
	printPreOrder(root);

	return 0;
}