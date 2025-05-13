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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> parent(n);
        vector<int> rank(n,0);

        for(int i=0;i<n;i++){
            parent[i]= i;
        }

        int components= n;
        for(auto& conn : connections){
            int u= conn[0];
            int v= conn[1];

            int parent_u= find(parent,u);
            int parent_v= find(parent,v);

            if(parent_u != parent_v){
                Union(parent,rank,u,v);
                components--;
            }
        }
        return components-1;
    }
};