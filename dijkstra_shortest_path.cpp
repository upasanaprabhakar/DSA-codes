#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pp> >gr;
void add_edge(int u, int v, int wt, bool bi_dir=true){
    gr[u].push_back({v,wt});
    if(bi_dir){
        gr[v].push_back({u,wt});
    }
}

unordered_map<int,int> dijkstra(int src, int n){
    priority_queue<pp, vector<pp>, greater<pp> >pq; //{dist,node}
    unordered_set<int> vis;
    vector<int> via(n+1);
    unordered_map<int,int> mp;
    for(int i=0;i<=n;i++){
        mp[i]= INT_MAX;
    }

    pq.push({0,src});
    mp[src]= 0;
    while(!pq.empty()){
        pp curr= pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        
        //if shorter path is found to neighbour then update
        for(auto neighbour : gr[curr.second]){
            if(!vis.count(neighbour.first) && mp[neighbour.first] > mp[curr.second] + neighbour.second){
                pq.push({mp[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first]= curr.second;
                mp[neighbour.first]= mp[curr.second] + neighbour.second;
            }
        }
    }
    return mp;
}

int main()
{
    int n,m;
    cin>>n>>m;
    gr.resize(n+1, list<pp> ());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int> sp= dijkstra(src,n);
    int dest;
    cin>>dest;
    cout<<sp[dest]<<"\n";
    return 0;
}
/*
Example Test Case:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1
5
6 ->Output
*/