class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        //build freq map
        for(int x : nums){
            mp[x]++;
        }

        //create buckets
        vector<vector<int>> bucket(n+1);

        //fill buckets
        for(auto it : mp){
            bucket[it.second].push_back(it.first);
        }

        //collect ans from highest freq
        vector<int>ans;
        for(int i=n; i>=0 && ans.size()<k; i--){
            for(int x : bucket[i]){
                ans.push_back(x);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};