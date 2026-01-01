class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for(int i=0;i<n;i++){
            if(leftSum == total-leftSum-nums[i]){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};