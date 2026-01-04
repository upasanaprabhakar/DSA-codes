class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n= nums.size();
        int prefixSum = 0;
        int result = 0;
        mp[0] = 1;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];

            if(mp.find(prefixSum - k) != mp.end()){
                result += mp[prefixSum - k];
            }
            
            mp[prefixSum]++;
        }

        return result;   
    }

};