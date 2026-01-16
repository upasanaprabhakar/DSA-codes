class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l= 0;
        int maxLen = 0;
        int noz =0;

        for(int r=0;r<n;r++){
            if(nums[r] == 0){
                noz++;
            }

            while(noz>k){
                if(nums[l] == 0) noz--;
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};