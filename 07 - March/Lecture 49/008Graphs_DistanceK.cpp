/**
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // transform binary tree into an undirected graph
        
        unordered_map<TreeNode*, list<TreeNode*>> neighbourMap;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* front = q.front(); q.pop();
            if(front->left) {
                neighbourMap[front].push_back(front->left);
                neighbourMap[front->left].push_back(front);
                q.push(front->left);
            } 
            if(front->right) {
                neighbourMap[front].push_back(front->right);
                neighbourMap[front->right].push_back(front);
                q.push(front->right);
            }
        }
        
        // 2. find all the nodes in the graph at distance k from the target node
        
        unordered_map<TreeNode*, int> distMap;
        distMap[target] = 0; // distance of the target from itself is zero
        
        q.push(target);
        
        while(!q.empty()) {
            TreeNode* front = q.front(); q.pop();
            list<TreeNode*> neighbourList = neighbourMap[front];
            for(TreeNode* neighbour : neighbourList) {
                if(distMap.find(neighbour) == distMap.end()) {
                    distMap[neighbour] = distMap[front]+1;
                    q.push(neighbour);
                }
            }
        }
        
        vector<int> out;
        for(pair<TreeNode*, int> vertex : distMap) {
            TreeNode* node = vertex.first;
            int distance = vertex.second;
            if(distance == k) {
                out.push_back(node->val);
            }
        }
        
        return out;
        
    }
};