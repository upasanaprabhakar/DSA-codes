class Solution {
public:
    int maxDistance(vector<int>& c) {
        int n = c.size(), mx = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (c[i] != c[j])
                    mx = max(mx, j - i);
        return mx;
    }
};