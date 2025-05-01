#include<bits/stdc++.h>
using namespace std;

vector<list<int> >graph;
int v;  //no of vertices

void add_edge(int a, int b, bool bidir= true){
    graph[a].push_back(b);
    if(bidir){
        graph[b].push_back(a);
    }
}

void topologicalBFS(){
    //Kahn algo
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto neighbour : graph[i]){
            // i-->neighbour
            indegree[neighbour]++;
        }
    }
    queue<int> q;
    unordered_set<int> visited;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
            visited.insert(i);
        }
    }
    while(!q.empty()){
        int node= q.front();
        cout<<node<<" ";
        q.pop();
        for(auto neighbour : graph[node]){
            if(!visited.count(neighbour)){
                indegree[neighbour]--;
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
}

int main()
{
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y,false);
    }
    topologicalBFS();
    return 0;
}
/*
Example Test Case:
6 6   
5 2
5 0
4 0
4 1
2 3
3 1
4 5 0 1 2 3 
*/