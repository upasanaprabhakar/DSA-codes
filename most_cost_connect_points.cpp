class Solution {
    public:
        struct Edge {
            int u, v, cost;
        };
    
        // Custom comparator for sorting edges by cost
        static bool cmp(Edge& e1, Edge& e2) {
            return e1.cost < e2.cost;
        }
    
        int find(vector<int>& parent, int a) {
            return parent[a] = (parent[a] == a) ? a : find(parent, parent[a]);
        }
    
        void Union(vector<int>&par, vector<int>& rank, int a, int b){
        a=find(par,a);
        b=find(par,b);
        if(a == b) return;
        if(rank[a] >= rank[b]){
            rank[a]++;
            par[b] =a;
        }
        else{
            rank[b]++;
            par[a] =b;
        }
    }
    
        int minCostConnectPoints(vector<vector<int>>& points) {
            int n= points.size();
            vector<Edge> edges;
    
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int dist= abs(points[i][0] - points[j][0]) + 
                            abs(points[i][1] - points[j][1]);
                    edges.push_back({i,j,dist});
                }
            }
    
            sort(edges.begin(), edges.end(), cmp);
            vector<int> parent(n), rank(n,0);
            for(int i=0;i<n;i++){
                parent[i]= i;
            }
            int totalCost= 0, edgeCount= 0;
    
            //Kruskal's loop
            for(Edge& e : edges){
                if(find(parent,e.u) != find(parent,e.v)){
                    Union(parent, rank, e.u, e.v);
                    totalCost+= e.cost;
                    edgeCount++;
                    if(edgeCount == n-1) break;
                }
            }
            return totalCost;
        }
    };