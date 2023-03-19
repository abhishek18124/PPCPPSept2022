/*
    
    https://leetcode.com/problems/alien-dictionary/

*/

class Graph {
    
    public :
    
        unordered_map<char, list<char>> neighbourMap;
        
        Graph(unordered_set<char> vertexSet) {
            for(char vertex : vertexSet) {
                neighbourMap[vertex] = {};
            }
        }
        
        void addEdge(char u, char v) {
            // add a directed edge from 'u' to 'v'
            neighbourMap[u].push_back(v);
        }
    
        void printGraph() {
            for(pair<char, list<char>> vertex : neighbourMap) {
                char vertexLabel = vertex.first;
                list<char> neighbourList = vertex.second;
                cout << vertexLabel << " : ";
                for(char neighbour : neighbourList) {
                    cout << neighbour << " ";
                }
                cout << endl;
            }
        }

    string topologicalSort() {

        unordered_map<char, int> inDegreeMap;
        for(pair<char, list<char>> vertex : neighbourMap) {
            list<char> neighbourList = vertex.second;
            for(char neighbour : neighbourList) {
                inDegreeMap[neighbour]++;
            }
        }
        
        queue<char> q;
        for(pair<char, list<char>> vertex : neighbourMap) {
            char vertexLabel = vertex.first;
            if(inDegreeMap.find(vertexLabel) == inDegreeMap.end()) {
                // vertex's inDegree is zero i.e. it has no dependecy
                q.push(vertexLabel);
            }
        }

        string uniqueString = "";

        while(!q.empty()) {
            char front = q.front(); q.pop();
            uniqueString += front;
            list<char> neighbourList = neighbourMap[front];
            for(char neighbour : neighbourList) {
                inDegreeMap[neighbour]--;
                if(inDegreeMap[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        
        return uniqueString;
    }

};

class Solution {
public:
    
    string alienOrder(vector<string>& words) {
        
        int n = words.size();
        
        // handle incorrect input : ["abc","ab"] , here "abc" is not smaller than "ab" according to the alien language
        
        for(int i=0; i<n-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            if(word1.size() > word2.size() and word1.substr(0, word2.size()) == word2) {
                return "";
            }
        }
        
        unordered_set<char> charSet;
        for(string word : words) {
            for(char ch : word) {
                charSet.insert(ch);
            }
        }
        
        Graph g(charSet);
        
        for(int i=0; i<n-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            for(int j=0; j<min(word1.size(), word2.size()); j++) {
                if(word1[j] != word2[j]) {
                    // word1[j] < word2[j] in the alien language i.e. word2[j] depends on word1[j]
                    g.addEdge(word1[j], word2[j]);
                    break;
                }
            }
        }
        
        string uniqueString = g.topologicalSort();

        return uniqueString.size() == charSet.size() ? uniqueString : "";
        
    }
};