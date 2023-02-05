/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope. 
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the 
    ropes with minimum cost.

    Example :
    
    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(), ropeLengths.end());

    // for(int i=0; i<ropeLengths.size(); i++) {
    //     minHeap.push(ropeLengths[i]);
    // }

    int total = 0; // to track the total cost we will incur for merging the 'n' ropes into a single rope
    while(minHeap.size() > 1) {
        int x = minHeap.top(); minHeap.pop();
        int y = minHeap.top(); minHeap.pop();
        total += (x+y);
        minHeap.push(x+y);
    }

    cout << total << endl;

    return 0;
}