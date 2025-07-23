#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<pair<int, int>>> graph;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  int source = 1;
  vector<int> dist(n + 1, INT_MAX);
  dist[source] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, source});
  while (!pq.empty())
  {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (d > dist[u])
      continue;
    for (auto &edge : graph[u])
    {
      int v = edge.first;
      int w = edge.second;
      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << (dist[i] == INT_MAX ? -1 : dist[i]) << " ";
  }
  cout << "\n";

  return 0;
}
