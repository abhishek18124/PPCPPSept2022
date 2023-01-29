/*

	Given a BST and a key, design an algorithm to search for the key in the BST.	

	Output "true" is key is found otherwise output "false".

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

bool search(TreeNode* root, int key) {

	// base case
	if(!root) { // root == NULL
		// tree is empty
		return false;
	}

	// recursive case

	if(root->val == key) {
		return true;
	} else if(key < root->val) {
		// search for the key in the leftSubtree -> friend
		return search(root->left, key);
	} else {
		// search for the key in the rightSubtree -> friend
		return search(root->right, key);
	}

}

int main() {

	TreeNode* root = new TreeNode(10);
	
	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	search(root, 6) ? cout << "true" << endl :
	                   cout << "false" << endl;
	
	return 0;
}


