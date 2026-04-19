class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < m; i++) {
            int lo = i, hi = n - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (nums2[mid] >= nums1[i]) {
                    maxDist = max(maxDist, mid - i);
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        return maxDist;
    }
};