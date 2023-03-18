/*

https://leetcode.com/problems/clone-graph/

// Definition for a Node.

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

*/

class Solution {
public:
    Node* cloneGraph(Node* source) {
        
        if(!source) { // or source == NULL i.e. graph is empty
            return NULL;
        }
        
        unordered_map<Node*, Node*> cloneMap; // to store a mapping b/w nodes in the graph and their clones.
        queue<Node*> q; // to track vertices which have been cloned but the neighborList of the clone isn't populated.
        
        // create a clone of 'source'

        Node* source_clone = new Node(source->val);
        cloneMap[source] = source_clone;
        q.push(source);

        while(!q.empty()) {

           Node* front = q.front(); q.pop();

           vector<Node*> neighbourList = front->neighbors;
           for(Node* neighbour : neighbourList) {
            if(cloneMap.find(neighbour) == cloneMap.end()) {
                // neighbour is not cloned(visited)
                Node* neighbour_clone = new Node(neighbour->val);
                cloneMap[neighbour] = neighbour_clone;
                q.push(neighbour);
            }
            Node* front_clone = cloneMap[front];
            front_clone->neighbors.push_back(cloneMap[neighbour]);
           }
        
        }

        // return the clone of 'source'
            
        return source_clone; // or return cloneMap[source]
        
    }
};