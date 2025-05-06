class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n=nums.size();
            
            for(int i=0;i<n;i++){
                nums[i]= nums[i]+n*(nums[nums[i]]%n);   //original num
            }
    
            for(int i=0;i<n;i++){
                nums[i]= nums[i]/n;     //new num
            }
            return nums;
        }
    };