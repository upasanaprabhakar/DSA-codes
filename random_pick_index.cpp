class Solution {
public:
    unordered_map<int,vector<int>>mp;

    Solution(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){mp[nums[i]].push_back(i);}
    }
    
    int pick(int target) {
        vector<int>x=mp[target];
        return x[(rand())%(x.size())];
    }
};
