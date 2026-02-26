class Solution {
public:
    bool helper(vector<int>& nums, int idx, int target){
        if(target == 0){
            return true;
        }

        if(idx == nums.size()){
            return false;
        }

        if(nums[idx] > target){
            return helper(nums, idx+1, target);
        }

        bool include = helper(nums, idx+1, target-nums[idx]);
        bool exclude = helper(nums, idx+1, target);

        return include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums){
            total += num;
        }

        if(total % 2 != 0){
            return false;
        }

        return helper(nums, 0, total/2);
    }   
};