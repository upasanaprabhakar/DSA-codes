class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            if(board.empty() || board[0].empty()) {
                return;
            }
            
            int n = board.size();
            int m = board[0].size();
            queue<pair<int, int>> q;
            vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            
            // BFS for boundary 'O's (only boundary 'O' cells should be pushed to queue)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                        q.push({i, j});  // Push boundary 'O' cells
                        board[i][j] = 'S';  // Mark as visited (safe)
                    }
                }
            }
    
            // Perform BFS to mark connected 'O' cells from boundary as safe ('S')
            while (!q.empty()) {
                auto cell = q.front(); q.pop();
                int i = cell.first;
                int j = cell.second;
                
                for (int d = 0; d < 4; d++) {
                    int nr = i + dir[d][0];
                    int nc = j + dir[d][1];
    
                    // Skip out-of-bound cells
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (board[nr][nc] == 'O') {
                        board[nr][nc] = 'S';  // Mark as safe
                        q.push({nr, nc});
                    }
                }
            }
    
            // Convert all 'O' cells to 'X' 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'X';  // Surrounded 'O' -> 'X'
                    }
                    if (board[i][j] == 'S') {
                        board[i][j] = 'O';  // Safe 'O' -> 'O'
                    }
                }
            }
        }
    };
    