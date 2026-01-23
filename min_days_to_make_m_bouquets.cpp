class Solution {
public:
    bool isPossible(vector<int>&bloomDay, int day, int m, int k){
        int bouquets = 0;
        int count = 0;
        for(int bloom : bloomDay){
            if(bloom <= day){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return bouquets >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if((long long)m*k > n) return -1;
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(isPossible(bloomDay, mid, m, k)){
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