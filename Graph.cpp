// // #include <iostream>
// // #include <vector>
// // #include <queue>
// // using namespace std;

// // // Function to add edges to an undirected graph
// // void addedge(vector<vector<int>>& graph, int u, int v) {
// //     graph[u].push_back(v);
// //     graph[v].push_back(u);
// // }

// // // Function to add edges to a directed graph
// // void addedge1(vector<vector<int>>& graph, int u, int v) {
// //     graph[u].push_back(v);
// // }

// // // Function to print the graph
// // void printGraph(const vector<vector<int>>& graph) {
// //     for (int i = 0; i < graph.size(); i++) {
// //         cout << i << " -> ";
// //         for (int j = 0; j < graph[i].size(); j++) {
// //             cout << graph[i][j] << " ";
// //         }
// //         cout << endl;
// //     }
// // }

// // // BFS function
// // void BFS(const vector<vector<int>>& graph, int start) {
// //     vector<bool> visited(graph.size(), false); // Track visited vertices
// //     queue<int> q; // Queue for BFS
// //     visited[start] = true; // Mark the starting vertex as visited
// //     q.push(start); // Enqueue the starting vertex

// //     cout << "BFS traversal starting from vertex " << start << ": ";

// //     while (!q.empty()) {
// //         int vertex = q.front(); // Get the front vertex
// //         q.pop(); // Dequeue it
// //         cout << vertex << " "; // Print the visited vertex

// //         // Visit all the adjacent vertices
// //         for (int neighbor : graph[vertex]) {
// //             if (!visited[neighbor]) { // If the neighbor hasn't been visited
// //                 visited[neighbor] = true; // Mark it as visited
// //                 q.push(neighbor); // Enqueue it
// //             }
// //         }
// //     }
// //     cout << endl; // New line after traversal
// // }

// // int main() {
// //     vector<vector<int>> graph(5);
    
// //     // Adding directed edges
// //     addedge1(graph, 0, 1);
// //     addedge1(graph, 0, 4);
// //     addedge1(graph, 1, 2);
// //     addedge1(graph, 1, 3);
// //     addedge1(graph, 1, 4);
// //     addedge1(graph, 2, 3);
// //     addedge1(graph, 3, 4);

// //     // Print the graph
// //     printGraph(graph);
    
// //     // Perform BFS starting from vertex 0
// //     BFS(graph, 0);

// //     return 0;
// // }




// // #include <iostream>
// // #include <vector>
// // #include <queue>
// // using namespace std;

// // // Function to add edges to a directed graph
// // void addedge1(vector<vector<int>>& graph, int u, int v) {
// //     graph[u].push_back(v);
// // }

// // // Function to print the graph
// // void printGraph(const vector<vector<int>>& graph) {
// //     for (int i = 0; i < graph.size(); i++) {
// //         cout << i << " -> ";
// //         for (int j = 0; j < graph[i].size(); j++) {
// //             cout << graph[i][j] << " ";
// //         }
// //         cout << endl;
// //     }
// // }

// // // BFS function
// // void BFS(const vector<vector<int>>& graph, int start) {
// //     vector<bool> visited(graph.size(), false); // Track visited vertices
// //     queue<int> q; // Queue for BFS
// //     visited[start] = true; // Mark the starting vertex as visited
// //     q.push(start); // Enqueue the starting vertex

// //     cout << "BFS traversal starting from vertex " << start << ": ";

// //     while (!q.empty()) {
// //         int vertex = q.front(); // Get the front vertex
// //         q.pop(); // Dequeue it
// //         cout << vertex << " "; // Print the visited vertex

// //         // Visit all the adjacent vertices
// //         for (int neighbor : graph[vertex]) {
// //             if (!visited[neighbor]) { // If the neighbor hasn't been visited
// //                 visited[neighbor] = true; // Mark it as visited
// //                 q.push(neighbor); // Enqueue it
// //                 cout << "Visited " << neighbor << endl; // Log the visit
// //             }
// //         }
// //     }
// //     cout << endl; // New line after traversal
// // }

// // int main() {
// //     vector<vector<int>> graph(5);
    
// //     // Adding directed edges
// //     addedge1(graph, 0, 1);
// //     addedge1(graph, 0, 4);
// //     addedge1(graph, 1, 2);
// //     addedge1(graph, 1, 3);
// //     addedge1(graph, 1, 4);
// //     addedge1(graph, 2, 3);
// //     addedge1(graph, 3, 4);

// //     // Print the graph
// //     printGraph(graph);
    
// //     // Perform BFS starting from vertex 0
// //     BFS(graph, 0);

// //     return 0;
// // }



// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int node, edge;
//     cin >> node >> edge;
//     vector<int> graph[node + 1]; // Adjacency list

//     for (int i = 1; i <= edge; i++) { // 1-based indexing for clarity
//         int a, b;
//         cout << "Enter edge " << i << " (format: node1 node2): ";
//         cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     for (int i = 1; i <= node; i++) { // Adjust if nodes are 0-indexed
//         cout << i << "-->";
//         for (int j = 0; j < graph[i].size(); j++) {
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }



// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// void bfs(const vector<vector<int>>& graph, int start) {
//     int n = graph.size();
//     vector<bool> visited(n, false);
//     queue<int> q;

//     visited[start] = true;
//     q.push(start);

//     cout << "BFS Traversal: ";
//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();
//         cout << node << " ";

//         for (int i = 0; i < n; i++) {
//             if (graph[node][i] == 1 && !visited[i]) {
//                 visited[i] = true;
//                 q.push(i);
//             }
//         }
//     }
//     cout << endl;
// }

// int main() {
//     int n;
//     cout << "Enter the number of nodes: ";
//     cin >> n;

//     vector<vector<int>> graph(n, vector<int>(n));
//     cout << "Enter the adjacency matrix (row-wise):\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> graph[i][j];
//         }
//     }

//     int start;
//     cout << "Enter the starting node: ";
//     cin >> start;

//     bfs(graph, start);

//     return 0;
// }


/*

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void dfs(unordered_map<int, vector<int>>& graph, int u, vector<bool>& visited) {
    // Base case: if node u is already visited, return
    if (visited[u]) {
        return;
    }
    // Mark the current node as visited
    visited[u] = true;
    cout << u << " "; // Print the node
    // Recursively visit all adjacent nodes
    for (auto v : graph[u]) {
        dfs(graph, v, visited);
    }
}


void bfs(unordered_map<int, vector<int>>&mp, int u, vector<bool>&visited,vector<int>&res){
    queue<int> qt;
    qt.push(u);
    visited[u]=true;
    while(!qt.empty()){
        int node=qt.front();
        qt.pop();
        res.push_back(node);
        for(auto it:mp[node]){
            if(!visited[it]){
                qt.push(it);
                visited[it]=true;
            }
        }
    }
}




int main(){
    unordered_map <int, vector<int>> graph;
    int m, n;
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // for(auto i: graph){
    //     cout << i.first << " -> ";
    //     for(auto j: i.second){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // vector<bool> visited(n+1, false);
    // dfs(graph, 1, visited);
    // return 0;
    vector <int> res;
    vector <bool> visited(n+1, false);
    bfs(graph, 1, visited, res);
    for(auto i: res){
        cout << i << " ";
    }
    return 0;
}




*/


/*     Check if a Word is found in a matrix   */



// #include <iostream>
// #include <queue>
// #include <vector>
// #include <unordered_map>
// #include <string>
// using namespace std;

// bool WordSearch(unordered_map<char, vector<char>>& graph, char start, vector<bool>& visited, string& word) {
//     if (word.empty()) {
//         return true;
//     }

//     if (visited[start - 'A']) { // Assuming nodes are uppercase alphabets.
//         return false;
//     }

//     visited[start - 'A'] = true;

//     char current = word[0];
//     if (current == start) {
//         string remainingWord = word.substr(1);
//         for (char neighbor : graph[start]) {
//             if (WordSearch(graph, neighbor, visited, remainingWord)) {
//                 return true;
//             }
//         }
//     }

//     visited[start - 'A'] = false;
//     return false;
// }


// /*Cycle detection*/


// bool dfsCycle(unordered_map<int,vector<int>>&graph, int start, int parent, vector<bool>& visited){
//     visited[start] = true;
//     for(auto &v: graph[start]){
//         if(v==parent) continue;
//         if(visited[v]) return true;
//         if(dfsCycle(graph,v,start,visited)) return true;
//     }
//     return false;
// }



// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <queue>
// using namespace std;

// pair<int, bool> bfsCycle(unordered_map<int, vector<int>>& graph, int start, vector<bool>& visited) {
//     queue<pair<int, int>> q;
//     q.push({start, -1});
//     visited[start] = true;

//     unordered_map<int, bool> cycleNodes;
//     cycleNodes[start] = true;

//     while (!q.empty()) {
//         int node = q.front().first;
//         int parent = q.front().second;
//         q.pop();

//         for (auto& v : graph[node]) {
//             if (!visited[v]) {
//                 visited[v] = true;
//                 q.push({v, node});
//                 cycleNodes[v] = true;
//             } else if (v != parent) {
//                 // If a cycle is detected, count only the nodes involved in the cycle
//                 return {cycleNodes.size(), true};
//             }
//         }
//     }
//     return {0, false};
// }

// pair<int, bool> isCycle(unordered_map<int, vector<int>>& graph) {
//     vector<bool> visited(1000, false); // Assuming node values are within a reasonable range

//     for (auto& node : graph) {
//         int i = node.first;
//         if (!visited[i]) {
//             auto result = bfsCycle(graph, i, visited);
//             if (result.second) {
//                 return result;
//             }
//         }
//     }
//     return {0, false};
// }

// int main() {
//     unordered_map<int, vector<int>> graph;

//     cout << "Enter the number of nodes: ";
//     int n;
//     cin >> n;

//     cout << "Enter the number of edges: ";
//     int m;
//     cin >> m;

//     cout << "Enter the edges (e.g., 1 2 for an edge between 1 and 2):" << endl;
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }

//     pair<int, bool> res = isCycle(graph);
//     cout << "Is there a cycle in the graph? " << (res.second ? "Yes" : "No") << endl;
//     cout << "The number of nodes in the cycle is: " << res.first << endl;

//     return 0;
// }



#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;


/*DFS Traversal*/

/*UNDIRECTED CYCLE DETECTION IN A GRAPH USING DFS*/


bool isDfs(unordered_map<int,vector<int>> &graph, int start, vector<bool>&visited,int parent){
    visited[start] = true;
    for(auto i : graph[start]){
        if(!visited[i]){
            if(isDfs(graph,i,visited,start)){return true;}
        }
        else if(i != parent){
            return true;
        }
    }
    return false;
}


/*UNDIRECTED CYCLE DETECTION IN A GRAPH USING BFS*/


bool isBfs(unordered_map<int,vector<int>> &graph, int start, vector<bool>&visited){
    queue<pair<int,int>> q;
    q.push({start,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto i : graph[node]){
            if(visited[i] && i==parent) continue;
            if(!visited[i]){
                visited[i] = true;
                q.push({i,node});
            }
            else if(i != parent){
                return true;
            }
        }
    }
    return false;
}
    



bool isCycleUndirected(unordered_map<int, vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            // if(isDfs(graph, i, visited,-1)){return true;}
            if(isBfs(graph, i, visited)){return true;}
        }
    }
    return false;
}



/*DIRECTED CYCLE DETECTION IN A GRAPH USING DFS*/


bool dfs(unordered_map<int, vector<int>>& graph, int start, unordered_map<int, bool>& visited, unordered_map<int, bool>& inRecur) {
    visited[start] = true;
    inRecur[start] = true;
    for (auto it : graph[start]) {
        if (!visited[it]) {
            if (dfs(graph, it, visited, inRecur)) {
                return true;
            }
        }else if(inRecur[it]) {
            return true;
        }
    }
    inRecur[start] = false;
    return false;
}



/*DIRECTED CYCLE DETECTION IN A GRAPH USING BFS*/










bool isCycle(unordered_map<int, vector<int>>& graph) {
    unordered_map<int, bool> visited;
    unordered_map<int, bool> inRecur;
    for (auto it : graph) {
        if (!visited[it.first]) {
            if (dfs(graph, it.first, visited, inRecur)) {
                return true;
            }
        }
    }
    return false;
}




/*TOPOLOGICAL SORTED    -> this sorting algorith can we use only in directed acyclic graph     */  


void topoHelp(unordered_map<int,vector<int>> &Graph,vector<bool>&visited,int start,stack<int>&st){
    visited[start]=true;
    for(auto &it:Graph[start]){
        if(!visited[it]){
            topoHelp(Graph,visited,it,st);
        }
    }
    st.push(start);
}


vector <int> TopoSort(unordered_map<int,vector<int>> &Graph){
    int maxnode=0;
    for(auto &it:Graph){
        maxnode=max(it.first,maxnode);
    }
    stack<int> st;
    vector<bool> visited(maxnode+1,false);
    for(auto &it:Graph){
        if(!visited[it.first]){
            topoHelp(Graph,visited,it.first,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
} 


//Practise of topological sort

void helpTopo(unordered_map<int, vector<int>>&graph, vector<bool>&visited, int start, stack<int>&ans){
    visited[start]=true;
    for(auto &v:graph[start]){
        if(!visited[v]){
            helpTopo(graph,visited,v,ans);
        }
    }
    ans.push(start);
}

vector<int> Topo(unordered_map<int, vector<int>>&graph){
    int maxnode=INT_MIN;

    for(auto &v:graph){
        maxnode=max(maxnode,v.first);
        for(auto &M:v.second){
            maxnode=max(maxnode,M);
        }
    }
    stack<int> ans;
    vector<bool> visited(maxnode+1,false);
    for(int i=1;i<=maxnode;i++){
        if(!visited[i]){
            helpTopo(graph,visited,i,ans);
        }
    }
    vector <int> res;
    while(!ans.empty()){
        res.push_back(ans.top());
        ans.pop();
    }
    return res;
}






/*BFS KAHN's Algorithm*/

void helpKahns(unordered_map<int, vector<int>> &Graph, vector<int> &indegree, vector<int> &ans) {
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++) { // Corrected the loop condition
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto &it : Graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
}

vector<int> kahnsAlgo(unordered_map<int, vector<int>> &Graph) {
    int maxnode = 0;
    for (auto &it : Graph) {
        maxnode = max(it.first, maxnode);
        for (auto &i : it.second) {
            maxnode = max(i, maxnode);
        }
    }
    vector<int> indegree(maxnode + 1, 0);
    for (auto &it : Graph) {
        for (auto &i : it.second) {
            indegree[i]++;
        }
    }
    vector<int> ans;
    helpKahns(Graph, indegree, ans);
    return ans;
}




//Practise of kahn's Algorithm


void help(unordered_map<int,vector<int>>&graph,vector<int>&indegree,vector<int> &ans){
    queue<int> qt;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            qt.push(i);
        }
    }



    while(!qt.empty()){
        int node=qt.front();
        qt.pop();
        ans.push_back(node);
        for(auto &v:graph[node]){
            indegree[v]--;
            if(indegree[v]==0){
                qt.push(v);
            }
        }
    }
}


vector <int> Kahns(unordered_map<int, vector<int>>&Graph){
    int maxnode=INT_MIN;
    for(auto &N:Graph){
        int node=N.first;
        maxnode=max(node,maxnode);
        for(auto &M:N.second){
            maxnode=max(M,maxnode);
        }
    }
    vector<int> indegree(maxnode+1,0);
    
    for(auto &v:Graph){
        for(auto &k:v.second){
            indegree[k]++;
        }
    }

    vector<int>ans;
    help(Graph,indegree,ans);
    return ans;
}






/*---->  Detect cycle in directed graph using cycle  <-----*/




bool help(unordered_map<int,vector<int>>&Graph,vector<int>&Indegree,int count, int start){
    queue<int>qt;
    for(int i=0;i<Graph.size();i++){
        if(indegree[i]==0){
            qt.push(i);
        }
    }
    while (!qt.empty()){
        
    }
}


bool detectCycle(unordered_map<int,vector<int>>&Graph){

}




int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    unordered_map<int, vector<int>> graph;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    // if (isCycleUndirected(graph)) {
    //     cout << "Cycle is present" << endl;
    // } else {
    //     cout << "Cycle is not present" << endl;
    // }

    vector <int> res = Topo(graph);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
