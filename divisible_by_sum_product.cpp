class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        long long mul = 1, sum = 0;

        while(x > 0){
            int rem = x%10;
            mul *= rem;
            sum += rem;
            x /= 10;
        }

        long long total = mul + sum;

        return (n%total == 0);
    }
};