#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_set>
using namespace std;

vector<list<int> > graph;
unordered_set<int> visited;
vector<vector<int> > result;


int v;  //no of vertices
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void bfs(int src, int dest,vector<int>& dist){
    queue<int>q;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src]= 0;
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto neighbour :graph[curr]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour]=dist[curr] + 1;

            }
        }
    }
}

int main()
{
    cin>>v;
    graph.resize(v);
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,true);
    }
    int x,y;
    cin>>x>>y;
    vector<int>dist;
    bfs(x,y,dist);
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}