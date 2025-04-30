#include<iostream>
#include<vector>
using namespace std;

int find(vector<int>& parent, int x) {
    // TC: O(log*n)
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& rank, vector<int>& sz, vector<int>& minimal, vector<int>& maximal, int a, int b) {
    // TC: O(log*n)
    a = find(parent, a);
    b = find(parent, b);
    if (a == b) return;  // both a and b are in the same set

    if (rank[a] >= rank[b]) {
        parent[b] = a;
        sz[a] += sz[b];
        maximal[a] = max(maximal[a], maximal[b]);
        minimal[a] = min(minimal[a], minimal[b]);
        if (rank[a] == rank[b]) rank[a]++;
    } else {
        parent[a] = b;
        sz[b] += sz[a];
        maximal[b] = max(maximal[a], maximal[b]);
        minimal[b] = min(minimal[a], minimal[b]);
    }
}

int main() {
    ios::sync_with_stdio(false);  // Disable synchronization with C I/O
    cin.tie(NULL);  // Untie cin from cout for faster input

    int n, m;
    cin >> n >> m;
    
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    vector<int> sz(n + 1, 1);
    vector<int> minimal(n + 1);
    vector<int> maximal(n + 1);

    for (int i = 0; i <= n; i++) {
        parent[i] = minimal[i] = maximal[i] = i;
    }

    while (m--) {
        string str;
        cin >> str;
        if (str == "union") {
            int x, y;
            cin >> x >> y;
            Union(parent, rank, sz, minimal, maximal, x, y);
        } else {
            int x;
            cin >> x;
            x = find(parent, x);
            cout << minimal[x] << " " << maximal[x] << " " << sz[x] << "\n";
        }
    }

    return 0;
}
/*Example Test Case:
union 1 2
union 2 3
find 1
union 4 5
union 5 6
find 5
union 3 6
find 4
1 3 3
4 6 3
1 6 6
*/