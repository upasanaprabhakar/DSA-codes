class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        bool isFirstColZero= false;

        //Step 1: Use first row & cols to mark zeros
        for(int i=0;i<n;i++){
            if(matrix[i][0] == 0) isFirstColZero= true;
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;   //mark row
                    matrix[0][j] = 0;   //mark col
                }
            }
        }

        //Step 2: Use marks to set zeros
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        //Step 3: Handle first row
        if(matrix[0][0] == 0){
            for(int j=0;j<m;j++){
                matrix[0][j] = 0;
            }
        }

        //Step 3: Handle first column
        if(isFirstColZero){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
    }
};
