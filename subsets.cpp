class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& finalAns, int idx=0){
        if(nums.size()==idx){
            finalAns.push_back(ans);
            return;
        }
        helper(nums,ans,finalAns,idx+1);
        ans.push_back(nums[idx]);
        helper(nums,ans,finalAns,idx+1);
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        helper(nums,ans,finalAns);
        return finalAns;
    }
};