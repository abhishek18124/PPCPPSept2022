// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MIN));
        queue<pair<int, int>> q; 
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    // (i, j)th node corresponds to a rotten orange, hence can serve as a source for multi-source BFS
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        while(!q.empty()) {
            pair<int, int> front = q.front(); q.pop();
            int i = front.first; int j = front.second;
            for(int k=0; k<4; k++) {
                int ii = i+dx[k];
                int jj = j+dy[k];
                if(ii >= 0 and ii < m and jj >= 0 and jj < n and grid[ii][jj] == 1) {
                    // (ii, jj)th node corresponds to a fresh orange adjacent to a rotten orange at (i, j)th node
                    grid[ii][jj] = 2;
                    dist[ii][jj] = dist[i][j]+1;
                    q.push({ii, jj});
                }
            }
        }
        
        int timeElapsed = 0;
        int freshFlag = false; // assume no fresh oranges are present
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    // (i, j)th node corresponds to a fresh orange, this is possible because (i, j)th node 
                    // is part of a component that doesn't contain any rotten oranges hence it didn't rot.
                    timeElapsed = -1;
                    freshFlag = true;
                    break;
                }
                timeElapsed = max(timeElapsed, dist[i][j]);
            }
            if(freshFlag) {
                break;
            }
        }
        
        return timeElapsed;
        
    }
};