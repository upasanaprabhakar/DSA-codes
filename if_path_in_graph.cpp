class Solution {
public:
    int find(vector<int>& parent, int x){
        return parent[x]= (parent[x] == x)? x : find(parent,parent[x]);
    }

    void Union(vector<int>& parent, vector<int>& rank, int a, int b){
        a=find(parent,a);
        b=find(parent,b);

        if(rank[a] >= rank[b]){
            rank[a]++;
            parent[b]= a;
        }
        else{
            rank[b]++;
            parent[a]= b;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>parent(n),rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]= i;
        }
        int components= n;

        for(auto& edge : edges){
            int u= edge[0];
            int v= edge[1];
            Union(parent,rank,u,v);
        }
        return find(parent, source) == find(parent, destination);
    }
};