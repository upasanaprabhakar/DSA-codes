class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i]==9){
                nums[i]=0;
            }
            else{
                nums[i]=nums[i]+1;
                return nums;
            }

        }
        nums.insert(nums.begin(),1);
        return nums;

    }
};