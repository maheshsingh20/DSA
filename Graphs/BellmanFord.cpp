#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};

int main() {
    int node = 8;  // Number of nodes
    int conn = 10; // Number of edges

    vector<edge> Edge = {
        {0, 1, 3}, {0, 4, 1}, {0, 2, 3}, {1, 2, 1}, {4, 5, 1},
        {2, 3, 1}, {5, 3, 1}, {5, 6, 2}, {3, 7, 3}, {6, 7, 1}
    };

    vector<int> dist(node, INT_MAX);
    dist[0] = 0;

    // Relax all edges (node - 1) times
    for (int i = 0; i < node - 1; i++) {
        for (auto &[u, v, w] : Edge) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Output the shortest distances from source 0
    for (int i : dist) {
        if (i == INT_MAX)
            cout << "INF ";
        else
            cout << i << " ";
    }
    return 0;
}
