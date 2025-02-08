#include <bits/stdc++.h>
using namespace std;
#define int long long

// DFS: returns a pair {node, distance} representing the farthest node 
// from 'u' (starting with current distance 'd') along with its distance.
pair<int, int> dfs(int u, int parent, int d, const vector<vector<pair<int, int>>>& adj) {
    pair<int, int> res = {u, d};
    for (auto &edge : adj[u]) {
        int v = edge.first, w = edge.second;
        if (v == parent)
            continue;
        pair<int, int> candidate = dfs(v, u, d + w, adj);
        if (candidate.second > res.second)
            res = candidate;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Tree with n nodes and n-1 edges (weighted)
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // First DFS: from an arbitrary node (say 1) find the farthest node 'p'
    pair<int, int> p = dfs(1, 0, 0, adj);
    
    // Second DFS: from node 'p.first' find the farthest node 'q'
    pair<int, int> q = dfs(p.first, 0, 0, adj);
    
    // q.second holds the diameter, and q.first is the farthest node from p.first.
    cout << "Diameter of tree: " << q.second << "\n";
    cout << "Farthest node from node " << p.first << " is " << q.first << "\n";
    
    return 0;
}
