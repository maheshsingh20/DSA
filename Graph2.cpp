// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// // DFS traversal
// void dfs(vector<vector<int>>& graph, vector<bool>& vis, int src, vector<int>& ans) {
//     vis[src] = true;
//     ans.push_back(src);
//     for (auto& v : graph[src]) {
//         if (vis[v]) {
//             continue;
//         } else {
//             dfs(graph, vis, v, ans);
//         }
//     }
// }

// // BFS traversal
// void bfs(vector<vector<int>>& graph, vector<bool>& vis, int src, vector<int>& ans) {
//     queue<int> qt;
//     qt.push(src);
//     vis[src] = true;
//     while (!qt.empty()) {
//         int node = qt.front();
//         ans.push_back(node);
//         qt.pop();
//         for (auto& v : graph[node]) {
//             if (vis[v]) {
//                 continue;
//             } else {
//                 qt.push(v);
//                 vis[v] = true;
//             }
//         }
//     }
// }

// vector<int> traverse(vector<vector<int>>& graph) {
//     vector<bool> visited(graph.size(), false);
//     vector<int> ans;
//     for (int i = 0; i < graph.size(); i++) {
//         if (!visited[i]) {
//             bfs(graph, visited, i, ans); // You can switch to DFS if needed
//         }
//     }
//     return ans;
// }

// // Cycle detection using DFS in an undirected graph
// bool dfsCycleDetect(vector<vector<int>>& graph, vector<bool>& vis, int src, int parent) {
//     vis[src] = true;
//     for (auto& v : graph[src]) {
//         if (v == parent) {
//             continue;
//         } else if (!vis[v]) {
//             if (dfsCycleDetect(graph, vis, v, src)) {
//                 return true;
//             }
//         } else if (v != parent) {
//             return true;
//         }
//     }
//     return false;
// }

// bool detectCycle(vector<vector<int>>& graph) {
//     vector<bool> visited(graph.size(), false);
//     for (int i = 0; i < graph.size(); i++) {
//         if (!visited[i]) {
//             if (dfsCycleDetect(graph, visited, i, -1)) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// // Cycle detection using BFS
// bool bfsCycleDetect(vector<vector<int>>& graph, vector<bool>& vis, int src) {
//     queue<pair<int, int>> qt;
//     qt.push({src, -1});
//     vis[src] = true;
//     while (!qt.empty()) {
//         int node = qt.front().first;
//         int parent = qt.front().second;
//         qt.pop();
//         for (auto& v : graph[node]) {
//             if (!vis[v]) {
//                 qt.push({v, node});
//                 vis[v] = true;
//             } else if (v != parent) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool detectCycle1(vector<vector<int>>& graph) {
//     vector<bool> visited(graph.size(), false);
//     for (int i = 0; i < graph.size(); i++) {
//         if (!visited[i]) {
//             if (bfsCycleDetect(graph, visited, i)) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }



// //Cycle detection using DFS IN DIRECTED GRAPH




// bool dfsCycleDetect(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& inRecur, int src){
//     visited[src]=true;
//     inRecur[src]=true;
//     for(auto &v:graph[src]){
//         if(!visited[v]){
//             return dfsCycleDetect(graph,visited,inRecur,v);
//         }
//         else if(inRecur[v]){
//             return true;
//         }
//     }
//     inRecur[src]=false;
//     return false;
// }






// bool detectCyclex(vector<vector<int>>& graph){
//     vector<bool>visited(graph.size(),false);
//     vector<bool>inRecur(graph.size(),false);
//     for(int i=0;i<graph.size();i++){
//         if(!visited[i]){
//             if(dfsCycleDetect(graph,visited,inRecur,i)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }



// int main() {
//     int node;
//     cout << "Enter number of nodes:-> ";
//     cin >> node;
//     int edge;
//     cout << "Enter the number of edges:-> ";
//     cin >> edge;
//     vector<vector<int>> Grap(node);
//     for (int i = 0; i < edge; i++) {
//         int u, v;
//         cin >> u >> v;
//         Grap[u].push_back(v);
//         // Grap[v].push_back(u);
//     }

//     // For traversal (choose either DFS or BFS)
//     // vector<int> res = traverse(Grap);
//     // for (int i = 0; i < res.size(); i++) {
//     //     cout << res[i] << " ";
//     // }

//     if (detectCyclex(Grap)) {
//         cout << "Cycle detected";
//     } else {
//         cout << "No cycle detected";
//     }

//     return 0;
// }






