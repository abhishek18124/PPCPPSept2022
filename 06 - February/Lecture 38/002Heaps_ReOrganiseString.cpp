
#include<iostream>
#include<queue>

using namespace std;

string reOrganise(string str) {

    int freq[26] = {};

    // memset(freq, 0, sizeof(freq));

    // fill(freq, freq+26, 0);

    for(char ch : str) {
        freq[ch-'a']++;
    }

    priority_queue<pair<int, char>> maxHeap;

    for(int i=0; i<26; i++) {
        if(freq[i] > 0) {
            maxHeap.push({freq[i], i+'a'});
        }
    }

    while(!maxHeap.empty()) {
        if(maxHeap.size() == 1) {
            pair<int char> maxPair = maxHeap.top();
            if(maxPair.first == 1) {
                out += maxPair.second;
            } else {
                // we cannot reorganise the string
                out = "";
            }
        
        }  else {
            pair<int, char> firstMax = maxHeap.top();
            maxHeap.pop();

            out += firstMax.second;
            firstMax.first--;

            pair<int, char> secondMax = maxHeap.top();
            maxHeap.pop();

            out += secondMax.second;
            secondMax.first--;

            if(firstMax.first > 0) {
                maxHeap.push(firstMax);
            }

            if(secondMax.first > 0) {
                maxHeap.push(secondMax);
            } 
        }
    }

    return "";

    // string out = "";

    // ...

    // return out;

}

int main() {

    string str = "aaaaabbbbcccdd";
    cout << reOrganise(str) << endl;
    return 0;
}