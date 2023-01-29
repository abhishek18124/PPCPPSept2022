/*

	Given a inOrder traversal of a BST, design an algorithm to build a balanced BST.

*/

#include<iostream>
#include<queue>

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

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if(front->left) q.push(front->left);
			if(front->right)q.push(front->right);
		}
	}
}

TreeNode* buildBBST(int* A, int s, int e) {

	// base case
	if(s > e) {
		// contruct an empty tree
		return NULL;
	}

	// recursive case

	int m = s+(e-s)/2;
	TreeNode* root = new TreeNode(A[m]);

	// construct the leftSubtree using A[s...m-1]
	root->left = buildBBST(A, s, m-1);

	// construct the rightSubtree using A[m+1...e]
	root->right = buildBBST(A, m+1, e);

	return root;
}

int main() {

	int A[] = {3, 5, 7, 10, 13, 15, 17};
	int n = sizeof(A) / sizeof(int);

	TreeNode* root = buildBBST(A, 0, n-1);

	printLevelOrder(root);

	cout << endl;
	
	return 0;
}