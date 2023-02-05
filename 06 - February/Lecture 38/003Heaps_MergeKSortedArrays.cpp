/*

    Given k sorted arrays, merge them and print the sorted output.

    k = 3
    Input : {
                {1, 3, 5, 7}, 
                {2, 4, 6, 8}, 
                {0, 9, 10, 11}
            }

    Output: 0 1 2 3 4 5 6 7 8 9 10 11 

*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Triple {
    public :

        int val;
        int row;
        int col;

        Triple(int val, int row, int col) {
            this->val = val;
            this->row = row;
            this->col = col;
        }
};

class TripleComparator{

    public :

    bool operator()(Triple a, Triple b) {
        if(b.val < a.val) {
            // we need a swap for minHeap
            return true;
        } else {
            return false;
        }
    } 

};

int main() {

    vector<vector<int>> inp = {{1, 3, 5, 7}, 
                               {2, 4, 6, 8}, 
                               {0, 9, 10, 11}};

    int k = inp.size();

    priority_queue<Triple, vector<Triple>, TripleComparator> minHeap;

    for(int i=0; i<k; i++) {
        minHeap.push(Triple(inp[i][0], i, 0));
    }

    vector<int> out;

    while(!minHeap.empty()) {
        Triple t = minHeap.top(); 
        minHeap.pop();

        int val = t.val;
        int row = t.row;
        int col = t.col;

        out.push_back(val);

        if(col+1 < inp[row].size()) {
            minHeap.push(Triple(inp[row][col+1], row, col+1));
        }

    }

    for(int i=0; i<out.size(); i++) {
        cout << out[i] << " ";
    }

    cout << endl;

    return 0;
}