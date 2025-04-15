class Solution {
    public:
        void permutation(vector<vector<int>>&ans,vector<int>& nums,int i){
            if(i==nums.size()){
                ans.push_back(nums);
                return;
            }
            for(int idx=i;idx<nums.size();idx++){
                swap(nums[idx],nums[i]);
                permutation(ans,nums,i+1);
                swap(nums[idx],nums[i]); //undo change
            } 
        }
        vector<vector<int>> permute(vector<int>& nums) {
            int n=nums.size();
            int idx=0;
            vector<vector<int> >ans;
            permutation(ans,nums,idx);
            return ans;
        }
    };