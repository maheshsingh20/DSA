#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int primMST(int V, vector<vector<pii>>& adj) {
    vector<bool> vis(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    int cost = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        cost += w;

        for (auto [v, wt] : adj[u])
            if (!vis[v]) pq.push({wt, v});
    }
    return cost;
}

int main() {
    int V = 4;
    vector<vector<pii>> adj(V);

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 3});
    adj[0].push_back({3, 5});
    adj[1].push_back({0, 2});
    adj[1].push_back({3, 4});
    adj[2].push_back({0, 3});
    adj[2].push_back({3, 1});
    adj[3].push_back({0, 5});
    adj[3].push_back({1, 4});
    adj[3].push_back({2, 1});

    cout << primMST(V, adj) << "\n";
}
