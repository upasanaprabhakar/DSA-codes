class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(),nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] < nums[i+1] + nums[i+2]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        return 0;
    }
};

//  a + b > c,   a + c > b,   b + c > a.
 // if we sort in desc then a < b + c only check this