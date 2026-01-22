class Solution {
public:
    bool isPossible(vector<int>&piles, int k, int h){
        long long hours = 0;
        for(int p : piles){
            hours += (p+k-1)/k; 
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo= 1;
        int hi= *max_element(piles.begin(),piles.end());
        int ans = hi;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isPossible(piles,mid,h)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo= mid+1;
            }
        }
        return ans;
    }
};