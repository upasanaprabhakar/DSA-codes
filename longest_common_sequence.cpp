class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // insert all elements from nums into set
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int x : st) {
            if (!st.count(x - 1)) {
                int curr = x;
                int length = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    length++;
                }

                longest = max(longest, length);
            }
        }
        return longest;
    }
};