class Solution {
public:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j){
        int n= grid1.size();
        int m= grid1[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid2[i][j] == 0){
            return true;
        }

        bool isSub = true;
        grid2[i][j] = 0;

        if(grid1[i][j] == 0) isSub= false;

        bool up = dfs(grid1, grid2, i-1, j);
        bool down = dfs(grid1, grid2, i+1, j);
        bool left = dfs(grid1, grid2, i, j-1); 
        bool right = dfs(grid1, grid2, i, j+1);

        return isSub && up && down && left && right;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int count= 0;
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                if(grid2[i][j] == 1){
                    if(dfs(grid1, grid2, i, j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};