class Solution {
    public:
        void permutation(vector<vector<int>>&ans,vector<int>& nums,int i){
            if(i==nums.size()){
                ans.push_back(nums);
                return;
            }
            unordered_set<int> s;
            for(int idx=i;idx<nums.size();idx++){
                if(s.count(nums[idx])) continue;
                s.insert(nums[idx]);
                swap(nums[idx],nums[i]);
                permutation(ans,nums,i+1);
                swap(nums[idx],nums[i]); //undo change
            } 
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end()); // required to group duplicates
            vector<vector<int>> ans;
            permutation(ans, nums, 0);
            return ans;
        }
    };