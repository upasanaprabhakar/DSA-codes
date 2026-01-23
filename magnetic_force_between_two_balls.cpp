class Solution {
public:
    bool isPossible(vector<int>& position, int dist, int m){
        int count = 1;    // first ball placed
        int lastPos = position[0];  // position of first ball

        for(int i=1;i<position.size();i++){
            if(position[i]-lastPos >= dist){
                count++;
                lastPos = position[i];
            }
        }
        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = position.back() - position.front();
        int ans = 0;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isPossible(position, mid, m)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }  
        return ans;  
    }
};