class Solution {
public:
    void helper(vector<int>& candidates,int target ,vector<int>& curr, vector<vector<int>>& ans, int idx=0){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<candidates.size();i++){
            //skip duplicates
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }
            //skip
            if(candidates[i] > target){
                break;
            }
            curr.push_back(candidates[i]);
            //move to next index
            helper(candidates, target-candidates[i], curr, ans , i+1);
            
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        helper(candidates, target, curr, ans, 0);
        return ans;
    }
};