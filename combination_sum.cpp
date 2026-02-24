class Solution {
public:
    void helper(vector<int> & candidates, int target, vector<int>&curr, vector<vector<int>> &ans, int idx=0){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            //skip
            if(candidates[i] > target){
                continue;
            }

            curr.push_back(candidates[i]);
            //stay at the idx 
            helper(candidates, target-candidates[i], curr, ans, i);
            curr.pop_back();  //backtrack
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, curr, ans , 0);
        return ans;
    }
};