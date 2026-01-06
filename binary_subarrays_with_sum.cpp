class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int prefixSum = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];

            count += mp[prefixSum - goal];
            mp[prefixSum]++;
        }
        return count;
    }
};