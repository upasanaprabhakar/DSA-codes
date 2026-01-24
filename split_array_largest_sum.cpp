class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int limit){
        int subArray = 1;
        long long currSum = 0;

        for(int x: nums){
            if(currSum+x <= limit){
                currSum += x;
            }
            else{
                subArray++;
                currSum = x;
            }
        }
        return subArray <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(), nums.end(),0);
        int ans = hi;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(isPossible(nums, k, mid)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};