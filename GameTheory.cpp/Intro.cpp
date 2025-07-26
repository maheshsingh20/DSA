#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> dp;

bool dfs(int node, unordered_map<int, vector<int>> &graph)
{
  if (dp.count(node))
    return dp[node];
  if (graph[node].empty())
  {
    return dp[node] = false;
  }
  for (int neighbor : graph[node])
  {
    if (!dfs(neighbor, graph))
    {
      return dp[node] = true;
    }
  }
  return dp[node] = false;
}

int main()
{
  unordered_map<int, vector<int>> graph;
  graph[1] = {2, 3};
  graph[2] = {4};
  graph[3] = {4, 5};
  graph[4] = {6, 7};
  graph[5] = {6, 7};
  graph[6] = {8};
  graph[7] = {8};
  graph[8] = {};

  bool result = dfs(1, graph);
  cout << (result ? "True" : "False") << endl;

  return 0;
}
