bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<lastEndTime){
                ans++;
            }
            else{
                lastEndTime=intervals[i][1];
            }
        }
        return ans;
    }
};