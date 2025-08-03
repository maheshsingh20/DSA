#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS: ";
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            dfsUtil(nbr, adj, visited);
        }
    }
}

void dfs(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    cout << "DFS: ";
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfsUtil(i, adj, visited);
        }
    }
    cout << endl;
}

int countConnectedComponents(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsUtil(i, adj, visited);
            count++;
        }
    }
    return count;
}

bool hasCycleUndirectedUtil(int node, int parent, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[node] = true;
    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            if (hasCycleUndirectedUtil(nbr, node, visited, adj))
                return true;
        } else if (nbr != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycleUndirected(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleUndirectedUtil(i, -1, visited, adj))
                return true;
        }
    }
    return false;
}

bool hasCycleDirectedUtil(int node, vector<bool>& visited, vector<bool>& recStack, vector<vector<int>>& adj) {
    visited[node] = true;
    recStack[node] = true;

    for (int nbr : adj[node]) {
        if (!visited[nbr] && hasCycleDirectedUtil(nbr, visited, recStack, adj))
            return true;
        else if (recStack[nbr])
            return true;
    }

    recStack[node] = false;
    return false;
}

bool hasCycleDirected(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false), recStack(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleDirectedUtil(i, visited, recStack, adj))
                return true;
        }
    }
    return false;
}

void dfsTopo(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int nbr : adj[node]) {
        if (!visited[nbr])
            dfsTopo(nbr, adj, visited, st);
    }
    st.push(node);
}

void topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfsTopo(i, adj, visited, st);

    cout << "Topological Sort (DFS): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void kahnTopoSort(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
        for (int nbr : adj[i])
            indegree[nbr]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        topo.push_back(node);
        for (int nbr : adj[node]) {
            if (--indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    if (topo.size() != V)
        cout << "Cycle detected! Topo sort not possible.\n";
    else {
        cout << "Topological Sort (Kahn's): ";
        for (int x : topo) cout << x << " ";
        cout << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed graph
    }

    bfs(0, adj, V);
    dfs(V, adj);
    cout << "Connected Components: " << countConnectedComponents(V, adj) << endl;
    cout << "Cycle in Undirected Graph: " << (hasCycleUndirected(V, adj) ? "Yes" : "No") << endl;
    cout << "Cycle in Directed Graph: " << (hasCycleDirected(V, adj) ? "Yes" : "No") << endl;
    topoSortDFS(V, adj);
    kahnTopoSort(V, adj);
}
