class Solution {
public:
    bool backtrack(vector<int>& nums, vector<int>& bucket, int idx, int target){
        if(idx ==  nums.size()){
            return true;
        }

        for(int i=0;i<bucket.size();i++){
            if(bucket[i]+nums[idx] > target){
                continue;
            }

            bucket[i] += nums[idx];

            if(backtrack(nums,bucket,idx+1,target)){
                return true;
            }

            bucket[i] -= nums[idx];

            if(bucket[i] == 0){
                break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for(int x : nums){
            total += x;
        }

        if(total%k != 0){
            return false;
        }

        int target = total/k;
        vector<int>bucket(k,0);

        sort(nums.rbegin(), nums.rend());

        return backtrack(nums,bucket,0, target);
    }
};