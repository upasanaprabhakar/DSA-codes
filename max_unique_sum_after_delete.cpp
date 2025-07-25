class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = INT_MIN;
        unordered_set<int>s;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) 
               s.insert(nums[i]);
            else
               maxi = max(maxi,nums[i]);    
        }
        
        if(s.size() == 0)
           return maxi;
        
        int sum = 0;
        for(const int& val: s)
           sum += val;

        return sum;      
    }
};
