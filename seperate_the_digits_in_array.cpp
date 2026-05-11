class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            
            for(char ch:s){
                ans.push_back(ch-'0');
            }
        }
        return ans;
    }
};