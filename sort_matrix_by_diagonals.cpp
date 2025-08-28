class Solution {
public:
    int n;

    void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc){
        vector<int> vec;

        int i= r;
        int j= c;
        while(i<n && j<n){
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc){
            sort(begin(vec), end(vec));
        }
        else{
            sort(rbegin(vec), rend(vec));
        }

        i= r;
        j= c;
        for(int&val: vec){
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        //bottom
        for(int row=0; row<n; row++){
            sortDiagonal(row, 0, grid, false);
        }

        //top
        for(int col=1; col<n; col++){
            sortDiagonal(0, col, grid, true);
        }
        return grid;
    }
};