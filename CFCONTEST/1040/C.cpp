#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
class DisjointSet {
private:
    vi parent;
public:
    DisjointSet(int size) {
        parent.resize(size + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findSet(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findSet(parent[node]);
    }
    bool merge(int u, int v) {
        int rootU = findSet(u);
        int rootV = findSet(v);
        if (rootU == rootV) return false;
        parent[rootV] = rootU;
        return true;
    }
};
struct Connection {
    int from;
    int to;
    int weight;
    int index;
};
class EdgeConnector {
private:
    int edgeCount;
    vector<Connection> connections;
public:
    void input() {
        cin >> edgeCount;
        connections.resize(edgeCount);
        int highestNode = 0;
        for (int i = 0; i < edgeCount; ++i) {
            int u, v;
            cin >> u >> v;
            connections[i] = {u, v, v - u, i + 1};
            highestNode = max({highestNode, u, v});
        }
        processConnections(highestNode);
    }
    void processConnections(int maxNode) {
        sort(connections.begin(), connections.end(), [](const Connection &a, const Connection &b) {
            return a.weight > b.weight;
        });
        DisjointSet dsu(maxNode);
        vi selectedEdges;
        for (const auto& conn : connections) {
            if (dsu.merge(conn.from, conn.to)) {
                selectedEdges.push_back(conn.index);
            }
        }
        printResult(selectedEdges);
    }
  void printResult(const vi &edges) {
        cout << edges.size() << "\n";
        for (size_t i = 0; i < edges.size(); ++i) {
            cout << edges[i] << (i + 1 < edges.size() ? ' ' : '\n');
        }
    }
};
class ProblemHandler {
public:
    void execute() {
        int testCases;
        cin >> testCases;
        while (testCases--) {
            EdgeConnector solver;
            solver.input();
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ProblemHandler handler;
    handler.execute();
    return 0;
}
