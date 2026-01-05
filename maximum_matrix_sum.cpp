class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int countNeg = 0;

        int smallestNeg = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);

                if(matrix[i][j]<0){
                    countNeg++;
                }

                smallestNeg = min(smallestNeg, abs(matrix[i][j]));
            }
        }

        if(countNeg % 2 == 0){
            return sum;
        }

        return sum - 2*smallestNeg;
    }
};