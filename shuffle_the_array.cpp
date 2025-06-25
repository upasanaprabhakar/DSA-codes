class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);      // x1, x2, ...
            result.push_back(nums[i + n]);  // y1, y2, ...
        }
        return result;
    }
};
