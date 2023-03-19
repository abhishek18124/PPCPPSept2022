/*
	https://leetcode.com/problems/course-schedule-ii/
*/

template <typename T>
class Graph {
  
    public :
        
        unordered_map<T, list<T>> neighbourMap;
    
        Graph(int V) {
            // courses you have to take are labeled from 0 to V-1
            for(int i=0; i<V; i++) {
                neighbourMap[i] = {}; // or use list<int>() instead of {}
            }
        }
    
        void addEdge(T u, T v) {
            // adds a directed edge from u i.e. b_i to v i.e. a_i
            neighbourMap[u].push_back(v);
        }
    
        void printGraph() {
            for(pair<T, list<T>> vertex : neighbourMap) {
                T vertexName = vertex.first;
                list<T> neighbourList = vertex.second;
                cout << vertexName << " : ";
                for(T neighbour : neighbourList) {
                    cout << neighbour << " ";
                }
                cout << endl;
            }
        }
    
        vector<int> topologicalSort() {
            
            vector<int> couresOrder;
            
            unordered_map<T, int> inDegreeMap;
            for(pair<T, list<T>> vertex : neighbourMap) {
                list<T> neighbourList = vertex.second;
                for(T neighbour : neighbourList) {
                    inDegreeMap[neighbour]++;
                }
            }
            
            queue<T> q;
            for(pair<T, list<T>> vertex : neighbourMap) {
                T vertexLabel = vertex.first;
                if(inDegreeMap.find(vertexLabel) == inDegreeMap.end()) {
                    // vertexLabel has an inDegree of zero i.e. it has no dependency
                    q.push(vertexLabel);
                }
            }
            
            while(!q.empty()) {
                T front = q.front(); q.pop();
                couresOrder.push_back(front);
                list<T> neighbourList = neighbourMap[front];
                for(T neighbour : neighbourList) {
                    inDegreeMap[neighbour]--;
                    if(inDegreeMap[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            }
            
            return couresOrder;
        }
    
};

class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        Graph<int> g(numCourses); 

        for(int i=0; i<prerequisites.size(); i++) {
            // prerequisites[i]=[a_i, b_i] indicates that you must take course b_i 
            // first if you want to take course a_i i.e. course a_i depends on b_i
            int a_i = prerequisites[i][0];
            int b_i = prerequisites[i][1];
            g.addEdge(b_i, a_i);
        }
         
        g.printGraph();
        
        vector<int> courseOrder = g.topologicalSort();
        for(int vertex : courseOrder) {
            cout << vertex << " ";
        }

        return courseOrder.size() == numCourses ? courseOrder : vector<int>(); 
    }
};