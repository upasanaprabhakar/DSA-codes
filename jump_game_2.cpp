#define ll long long 
class Solution {
public:
    int dp[10005];
    ll f(vector<int>&nums,int curr,int end){
        if(curr==end) return 0;
        if(dp[curr]!=-1) return dp[curr];
        ll res=INT_MAX;
        for(int i=1;i<=nums[curr];i++){
            if(i+curr > end) break;
            res=min(res,1+f(nums,curr+i,end));
        }
        return dp[curr]=res;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof dp);
        return f(nums,0,n-1);
    }
};