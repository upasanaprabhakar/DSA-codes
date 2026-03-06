class Solution {
public:
    int dp[31][3001];
    int helper(vector<int>& stones, int i, int sum, int target){
        if(i == stones.size()){
            return sum;
        }

        if(dp[i][sum] != -1){
            return dp[i][sum];
        }

        int skip = helper(stones, i+1, sum, target);

        int take = sum;
        if(sum + stones[i] <= target){
            take = helper(stones,i+1,sum+stones[i],target);
        }

        return dp[i][sum] = max(skip, take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int total = 0;
        for(int s : stones){
            total += s;
        }
        int target = total/2;

        int best = helper(stones,0,0,target);

        return total - 2*best;
    }
};