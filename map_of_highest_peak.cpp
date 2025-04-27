class Solution {
    public:
        vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
            if(isWater.empty() || isWater[0].empty()) {
                return {};
            }
    
            int n = isWater.size();
            int m = isWater[0].size();
            queue<pair<int,int>> q;
            vector<vector<int>> height(n, vector<int>(m, -1));
    
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(isWater[i][j] == 1) {
                        q.push({i, j}); // Water cells
                        height[i][j] = 0; // Water height is 0
                    }
                }
            }
    
            vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
            while(!q.empty()) {
                auto cell = q.front(); q.pop();
                int i = cell.first;
                int j = cell.second;
    
                for(int d = 0; d < 4; d++) {
                    int nr = i + dir[d][0];
                    int nc = j + dir[d][1];
    
                    if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if(height[nr][nc] == -1) {
                        height[nr][nc] = height[i][j] + 1;
                        q.push({nr, nc});
                    }
                }
            }
            return height;
        }
    };
    