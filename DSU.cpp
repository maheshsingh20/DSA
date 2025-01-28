#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rankVal;

void makeset(char n) {
    parent.resize(26);
    rankVal.resize(26, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionset(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (rankVal[xroot] < rankVal[yroot]) {
        parent[xroot] = yroot;
    } else if (rankVal[xroot] > rankVal[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rankVal[xroot]++;
    }
}

bool isCycle(vector<vector<int>> &graph) {
    for (int u = 0; u < graph.size(); u++) {
        for (int v : graph[u]) {
            int x = find(u);
            int y = find(v);
            if (x == y) {
                return true; // Cycle detected
            }
            unionset(x, y);
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    makeset(n);

    // Create adjacency list
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    if (isCycle(graph)) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle" << endl;
    }

    return 0;
}
