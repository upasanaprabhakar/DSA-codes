class Solution {
public:
    int dp[301][5001];
    int helper(vector<int>& coins, int i, int amount){
        if(amount == 0) return 1;
        if(i == coins.size()) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int skip = helper(coins, i+1, amount);
        
        int take = 0;
        if(amount >= coins[i]){
            take = helper(coins, i, amount-coins[i]);
        }

        return dp[i][amount] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(coins,0,amount);
    }
};