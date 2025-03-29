class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            if(n==0) return 0;
            int dp[n];
            dp[0]=0;
            int minPrice=prices[0];
            for(int i=1;i<n;i++){
                int currProfit=prices[i]-minPrice;
                dp[i]=max(dp[i-1],currProfit);
                minPrice=min(minPrice,prices[i]);
            }
            return dp[n-1];
        }
    };