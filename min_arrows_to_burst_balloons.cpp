bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        sort(points.begin(),points.end(),cmp);
        int lastEndTime=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]<=lastEndTime){
                ans++;
            }
            else{
                lastEndTime=points[i][1];
            }
        }
        return points.size()-ans;
    }
};