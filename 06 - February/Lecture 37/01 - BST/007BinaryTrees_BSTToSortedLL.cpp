/*

	Given a BST, design an algorithm transform it into a sorted linked list in-place.

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


void printLinkedList(TreeNode* head) {
	while(head != NULL) {
		cout << head->val << " ";
		head = head->right;
	}

	cout << endl;
}

class Pair {

	public :

		TreeNode* head;
		TreeNode* tail;

};


Pair treeTolst(TreeNode* root) {

	Pair p;

	// base case
	if(!root) { // root == NULL
		// BST is empty
		p.head = p.tail = NULL;
		return p;
	}

	// recursive case

	// 1. transfor the leftSubtree which is a BST into a sorted Linked List
	Pair pL = treeTolst(root->left);

	if(pL.head != NULL) {
		pL.tail->right = root;
		p.head = pL.head; 
	} else {
		p.head = root;
	}


	// 2. transform the rightSubtree which is a BST into a sorted Linked List
	Pair pR = treeTolst(root->right);

	if(pR.head != NULL) {
		root->right = pR.head;
		p.tail = pR.tail;
	} else {
		p.tail = root;
	}

	return p;

}


int main() {

	TreeNode* root = new TreeNode(10);
	
	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	Pair p = treeTolst(root);

	printLinkedList(p.head);

	return 0;
}