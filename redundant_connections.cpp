class Solution {
public:
    int find(vector<int>& parent, int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
    }

    void Union(vector<int>& parent, vector<int>& rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a == b)
            return;
        if (rank[a] >= rank[b]) {
            parent[b] = a;
            rank[a]++;
        }

        else {
            parent[a] = b;
            rank[b]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int pu = find(parent, u);
            int pv = find(parent, v);

            if(pu != pv){
                Union(parent, rank, pu, pv);
            }
            else{
                return edge;
            }
        }
        return {};
    }
};