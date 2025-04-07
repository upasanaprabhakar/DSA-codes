class Solution {
    public:
        int dp[100005][2];
    
        int f(vector<int>& prices, int i, bool on) {
            if (i == prices.size()) return 0;
    
            int state = on;
            if (dp[i][state] != -1) return dp[i][state];
    
            int ans = f(prices, i + 1, on);  // skip
    
            if (on) {
                // Sell today
                ans = max(ans, prices[i] + f(prices, i + 1, false));
            } else {
                // Buy today
                ans = max(ans, f(prices, i + 1, true) - prices[i]);
            }
    
            return dp[i][state] = ans;
        }
    
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            memset(dp, -1, sizeof dp); 
            return f(prices, 0, false);  
        }
    };
    