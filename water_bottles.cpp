class Solution {
public:
    int numWaterBottles(int b, int n) {
        // b = initial full bottles, n = empties needed for 1 full
        // return total drinks including ones from exchanging empties
        return b + (b - 1) / (n - 1);
    }
};
