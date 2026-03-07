class Solution {
public:
    int dp[10001];
    int helper(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return 1e9;

        if(dp[amount] != -1){
            return dp[amount];
        }

        int ans = 1e9;
        for(int coin : coins){
            int res = 1+helper(coins, amount-coin);
            ans = min(ans, res);
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));

        int ans = helper(coins,amount);

        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};