class Solution {
    public:
        vector<int> parent, rank;
    
        // DSU find with path compression
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
    
        // DSU union by rank
        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py) return;
            if (rank[px] < rank[py])
                parent[px] = py;
            else if (rank[px] > rank[py])
                parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
    
        int removeStones(vector<vector<int>>& stones) {
            int OFFSET = 10001;       // To avoid collision between row and col indices
            int maxSize = 20005;      // Total size of DSU array
            parent.resize(maxSize);
            rank.resize(maxSize, 0);
    
            // Initialize DSU: each node is its own parent
            for (int i = 0; i < maxSize; ++i)
                parent[i] = i;
    
            unordered_set<int> nodes; // Keeps track of all unique nodes (rows + cols)
    
            // Connect each stone's row and col using DSU
            for (auto& stone : stones) {
                int row = stone[0];
                int col = stone[1] + OFFSET;
                unite(row, col);
                nodes.insert(row);
                nodes.insert(col);
            }
    
            unordered_set<int> uniqueParents;
    
            // Count how many unique connected components exist
            for (int node : nodes)
                uniqueParents.insert(find(node));
    
            // Maximum stones that can be removed = total stones - number of components
            return stones.size() - uniqueParents.size();
        }
    };
    