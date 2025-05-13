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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int>parent(n);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++){
            parent[i]= i;
        }
        int components= n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] == 1){
                    int parent_i= find(parent,i);
                    int parent_j= find(parent,j);
                    if(parent_i != parent_j){
                        Union(parent,rank,i,j);
                        components--;
                    }
                }
            }
        }
        return components;
    }
};