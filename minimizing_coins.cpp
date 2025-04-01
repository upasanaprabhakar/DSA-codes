#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int>coins;
vector<int>dp(1000006,-2);
int fn(int x){
    if(x==0) return 0;
    if(dp[x]!=-2) return dp[x];
    int result=INT_MAX;

    for(int i=0;i<coins.size();i++){
        if(x-coins[i]<0) continue;
        result=min(result,fn(x-coins[i]));
    }
    if(result==INT_MAX) return dp[x]=INT_MAX;
    return dp[x]=1+result;
}

int main()
{   
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        coins.push_back(num);
    }
    cout<<fn(x)<<endl;
    return 0;
}