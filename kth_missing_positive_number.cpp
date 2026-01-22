class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int lo= 0;
        int hi= nums.size()-1;
        
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            int missing = nums[mid] - (mid+1);

            if(missing < k){
                lo= mid+1;
            }
            else{
                hi= mid-1;
            }
        }
        int ans = lo+k;
        return ans;
    }
};