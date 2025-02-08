#include <bits/stdc++.h>
using namespace std;
#define int long long

// Performs BFS on an unweighted graph from source 's'.
// Returns a vector of distances (1-indexed). Unreachable nodes have distance -1.
vector<int> bfsGraph(int n, const vector<vector<int>>& adj, int s) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // Assuming an undirected graph.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int s;
    cin >> s; // Source node for BFS.
    vector<int> dist = bfsGraph(n, adj, s);
    
    for (int i = 1; i <= n; i++){
        cout << "Distance from " << s << " to " << i << " is " << dist[i] << "\n";
    }
    return 0;
}
