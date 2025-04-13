#define ll long long 
class Solution {
public:
    int dp[10005];
    ll f(vector<int>&nums,int curr,int end){
        if(curr==end) return true;
        if(dp[curr]!=-1) return dp[curr];
        for(int i=1;i<=nums[curr];i++){
            if(i+curr <= end && f(nums,curr+i,end)){
                return dp[curr]=true;;
            }
            
        }
        return dp[curr]=false;
    } 
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof dp);
        return f(nums,0,n-1);
    }
};