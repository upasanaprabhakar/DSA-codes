class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n= nums.size();
        int count_e =0;
        int count_o =0;

        for(auto& num: nums){
            if(num%2 == 0){
                count_e++;
            }
            else{
                count_o++;
            }
        }

        int alternating=1;
        int parity = nums[0]%2;

        for(int i=0;i<n;i++){
            int currParity = nums[i]%2;
            if(currParity != parity){
                alternating++;
                parity = currParity;
            }
        }
        return max({count_e, count_o, alternating});
    }
};

