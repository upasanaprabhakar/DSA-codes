class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int count =0;
        int prefixSum = 0;
        mp[0] = 1;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];

            int rem = prefixSum%k;
            if(rem<0) rem += k;

            count += mp[rem];
            mp[rem]++;
            
        }
        return count;
    }
};