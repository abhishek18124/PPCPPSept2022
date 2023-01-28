/*

given the pre-order traversal of a binary tree, design a recursive algorithm 
to compute its diameter

	  diameter of a binary tree is the length of the longest path between any 
	  two TreeNodes in the binary tree.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 5

          Input  : 10 20 30 50 -1 -1 -1 40 -1 60 -1 -1 70 -1 -1
          Output : 4
          
          Input  : 10 20 -1 -1 30 40 60 -1 -1 -1 50 -1 70 -1 -1
          Output : 4
          
*/

#include<iostream>
#include<cmath>

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
	if(!root) { // root == NULL
		// height of empty tree is -1
		return -1;
	}

	// recursive case

	// 1. ask your friend for the height of the leftSubtree
	int X = computeHeight(root->left);

	// 2. ask your friend for the height of the rightSubtree
	int Y = computeHeight(root->right);

	return 1 + max(X, Y);

}


int computeDiameter(TreeNode* root) {

	// base case
	if(!root) { // root == NULL
		// tree is empty, therefore diameter is zero
		return 0;
	}

	// recursive case

	// 1. compute the diameter of the leftSubtree
	int dL = computeDiameter(root->left);

	// 2. compute the diamter of the rightSubtree
	int dR = computeDiameter(root->right);

	// 3. compute the length of the longest path that goes through the root node
	int rL = computeHeight(root->left) + computeHeight(root->right) + 2;

	return max({dL, dR, rL});

}

class Pair {

	public :

		int diameter;
		int height;
};


Pair computeDiameterEfficient(TreeNode* root) {

	Pair p;

	// base case
	if(!root) { // root == NULL
		// tree is empty, therefore diameter is zero
		p.diameter = 0;
		p.height = -1;
		return p;
	}

	// recursive case

	// 1. compute the diameter & the height of the leftSubtree
	Pair pL = computeDiameterEfficient(root->left);

	// 2. compute the diamter & the height of the rightSubtree
	Pair pR = computeDiameterEfficient(root->right);

	// 3. compute the length of the longest path that goes through the root node
	int rL = pL.height + pR.height + 2;

	p.diameter = max({pL.diameter, pR.diameter, rL});
	p.height = 1 + max(pL.height, pR.height);

	return p;

}

int main() {

	TreeNode* root = buildTree();

	// cout << computeDiameter(root) << endl;

	Pair p = computeDiameterEfficient(root);

	cout << p.diameter << endl;

	return 0;
}