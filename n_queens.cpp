class Solution {
    public:
        vector<vector<char>>grid;
        vector<vector<string>>result;
        bool CanPlaceQueen(int row,int col,int n){
            //column check
            for(int i=row-1;i>=0;i--){
                if(grid[i][col]=='Q')//we are attacked
                    return false;
            }
            //left diagonal check
            for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
                if(grid[i][j]=='Q')//we are attacked
                    return false;
            }
            //right diagonal check
            for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
                if(grid[i][j]=='Q')//we are attacked
                    return false;
            }
            return true; //no attack found
        }
        void f(int row,int n){
            if(row==n){ //we got a possible ans
                vector<string>temp;
                for(int i=0;i<n;i++){
                    string res="";
                    for(int j=0;j<n;j++){
                        res+=grid[i][j];
                    }
                    temp.push_back(res);
                }
                result.push_back(temp);
                return;
            }
            for(int col=0;col<n;col++){
                if(CanPlaceQueen(row,col,n)){
                    grid[row][col]='Q';
                    f(row+1,n);
                    grid[row][col]='.';
                }
            }
        }
        vector<vector<string>> solveNQueens(int n) {
            grid.clear();
            result.clear();
            grid.resize(n,vector<char>(n,'.'));
            f(0,n);
            return result;
        }
    };