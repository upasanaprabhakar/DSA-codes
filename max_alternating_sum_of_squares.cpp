class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        long long ans = 0;
        while(i<=j){
            if(i==j){
               ans = ans+nums[j]; 
            }
            else ans = ans+nums[j]-nums[i];
            i++;
            j--;
        }
        return ans;
    }
};