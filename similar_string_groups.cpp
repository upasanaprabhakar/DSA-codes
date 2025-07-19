class Solution {
public:
    int find(vector<int> &parent, int x){
        return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
    }

    void Union(vector<int> &parent, vector<int> &rank, int a, int b){
        a= find(parent, a);
        b= find(parent, b);

        if(rank[a] >= rank[b]){
            parent[b] = a;
            rank[a]++;
        }
        else{
            parent[a] = b;
            rank[b]++;
        }

    }

    bool isSimilar(const string &a, const string &b){
        int diff = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                diff++;
            }
            if(diff > 2) return false;
        }
        return diff==2 || diff==0;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n= strs.size();
        vector<int> parent(n);
        vector<int> rank(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i], strs[j])){
                    Union(parent, rank, i, j);
                }
            }
        }

        unordered_set<int> uniqueParents;

        for(int i=0;i<n;i++){
            uniqueParents.insert(find(parent,i));
        }

        return uniqueParents.size();
    }
};