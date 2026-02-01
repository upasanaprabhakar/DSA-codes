class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int smallest=INT_MAX,second_smallest=INT_MAX;

        for (int i=1;i<n;i++)
        {
            if (nums[i]<smallest)
            {
                second_smallest=smallest;
                smallest=nums[i];
                continue;
            }
            if (nums[i]<second_smallest)
                second_smallest=nums[i];
        }

        return nums[0]+smallest+second_smallest;
    }
};
