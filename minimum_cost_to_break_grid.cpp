#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define ll long long int
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

ll minCostToBreakGrid(int n,int m,vector<ll> &vertical,vector<ll> &horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz=1;
    int vr=1;
    int h=0,v=0;
    ll ans=0;
    while(h<horizontal.size() && v<vertical.size()){
        if(vertical[v]>horizontal[h]){
            ans+=vertical[v]*vr;
            hz++;
            v++;
        }
        else{
            ans+=horizontal[h]*hz;
            vr++;
            h++;
        }
    }

    while(h<horizontal.size()){
        ans+=horizontal[h]*vr;
        vr++;
        h++;
    }
    while(v<vertical.size()){
        ans+=vertical[v]*hz;
        hz++;
        v++;
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>m>>n;
    vector<ll>horizontal,vertical;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        vertical.push_back(x);
    }
    for(int i=0;i<m-1;i++){
        int x;
        cin>>x;
        horizontal.push_back(x);
    }
    cout<<minCostToBreakGrid(n,m,horizontal,vertical);
    return 0;
}