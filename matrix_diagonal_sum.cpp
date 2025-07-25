class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for(int i = 0; i < n; i++) {
            sum += mat[i][i]; // Primary diagonal
            sum += mat[i][n - i - 1]; // Secondary diagonal
        }
        if(n % 2 == 1) {
            sum -= mat[n/2][n/2]; // Subtract middle element if counted twice
        }
        return sum;
    }
};
