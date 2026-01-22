class Solution {
public:
    bool isPossible(vector<int>&weights, int capacity, int days){
        int currLoad = 0;
        int day = 1;
        for(int w: weights){
            if(currLoad+w <= capacity){
                currLoad += w;                
            }
            else{
                day++;
                currLoad = w;
            }
        }
        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo= *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        int ans = hi;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isPossible(weights, mid, days)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;   
    }
};