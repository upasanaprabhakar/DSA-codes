class Solution {
public:
    unordered_map<string,int> dp;
    int helper(vector<int>& nums, int idx, int sum, int target){
        if(idx == nums.size()){
            return (sum == target) ? 1 : 0;
        }
        string key = to_string(idx) + "," + to_string(sum);

        if(dp.count(key)){
            return dp[key];
        }

        int add = helper(nums,idx+1,sum+nums[idx],target);
        int subtract = helper(nums, idx+1, sum-nums[idx], target);

        return dp[key] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return  helper(nums,0,0,target);
    }
};