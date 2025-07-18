class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int &area){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>= n || j>=m || grid[i][j]!= 1) return;

        area++;
        grid[i][j]= 0;
        dfs(grid, i+1, j, area);
        dfs(grid, i-1, j, area);
        dfs(grid, i, j+1, area);
        dfs(grid, i, j-1, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea= 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea= max(ara, maxArea);
                }
            }
        }
        return maxArea;
    }
};