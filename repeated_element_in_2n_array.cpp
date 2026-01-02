class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums){
            mp[x]++;
            if(mp[x] > 1){
                return x;
            }
        }
        return -1;
    }
};