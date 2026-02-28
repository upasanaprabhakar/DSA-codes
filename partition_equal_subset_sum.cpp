class Solution {
public:
    bool helper(vector<int>& nums, int i , int target, vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }

        if(i == nums.size() || target<0){
            return false;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }

        //skip curr element
        bool exclude = helper(nums, i+1, target, dp);

        //include curr element
        bool include = false;
        if(target >= nums[i]){
            include = helper(nums, i+1, target-nums[i], dp);
        }

        return dp[i][target] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums){
            total += num;
        }

        if(total%2 != 0){
            return false;
        }

        int target = total/2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(nums, 0, target, dp);
    }
};