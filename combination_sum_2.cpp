class Solution {
    public:
        vector<vector<int> > result;
        void f(vector<int>&cand,int t,int idx,vector<int>&subset){
            if(t==0){
                //found a subset
                result.push_back(subset);
                return;
            }
            if(idx==cand.size()) return;
    
            //pick
            if(cand[idx]<=t){
                subset.push_back(cand[idx]);
                f(cand,t-cand[idx],idx+1,subset);
                subset.pop_back();
            }
            //avoid
            int j=idx+1;
            while(j<cand.size() && cand[j]==cand[j-1])j++;
            f(cand,t,j,subset);
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<int>subset;
            result.clear();
            f(candidates,target,0,subset);
            return result;
        }
    };