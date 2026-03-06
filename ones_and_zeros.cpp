class Solution {
public:
    int helper(vector<string>& strs, int i, int zeros, int ones, vector<vector<vector<int>>>& dp){
        if(i == strs.size()){
            return 0;
        }

        if(dp[i][zeros][ones] != -1){
            return dp[i][zeros][ones];
        }

        int z=0, o=0;
        for(char c : strs[i]){
            if(c == '0') z++;
            else o++;
        }

        int skip = helper(strs, i+1, zeros, ones, dp);
        int take = 0;
        if(zeros >= z && ones >= o){
            take = 1+helper(strs,i+1,zeros-z,ones-o,dp);
        }

        return dp[i][zeros][ones] = max(skip,take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>>dp(
            size, vector<vector<int>>(m+1, vector<int>(n+1,-1))
        );

        return helper(strs,0,m,n,dp);
    }
};