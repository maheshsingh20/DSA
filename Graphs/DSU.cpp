#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unionSet(int x, int y) {
        int lx = find(x);
        int ly = find(y);
        if (lx == ly) return;

        if (rank[lx] < rank[ly]) parent[lx] = ly;
        else if (rank[ly] < rank[lx]) parent[ly] = lx;
        else {
            parent[ly] = lx;
            rank[lx]++;
        }
    }
};

bool hasCycle(int V, vector<pair<int, int>>& edges) {
    DSU dsu(V);
    for (auto [u, v] : edges) {
        if (dsu.find(u) == dsu.find(v)) {
            return true; // cycle found
        }
        dsu.unionSet(u, v);
    }
    return false;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}  // This forms a cycle
    };

    cout << (hasCycle(V, edges) ? "Cycle found" : "No cycle") << endl;
    return 0;
}
