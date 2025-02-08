#include "bits/stdc++.h"
using namespace std;
#define int long long

// DFS to compute the size of the subtree rooted at node u.
// 'p' is the parent of u. The size is stored in the 'subtree' vector.
int dfs(int u, int p, vector<vector<int>> &adj, vector<int> &subtree) {
    int count = 1;  // Count the current node.
    for (int v : adj[u]) {
        if (v == p)
            continue;
        count += dfs(v, u, adj, subtree);
    }
    subtree[u] = count;
    return count;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // Build tree: n nodes and n-1 edges.
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Vector to store subtree sizes.
    vector<int> subtree(n + 1, 0);
    
    // Run DFS from node 1 (assuming 1 is the root) to compute subtree sizes.
    dfs(1, 0, adj, subtree);
    
    // Print the number of children for each node (subtree size minus one).
    for (int i = 1; i <= n; i++){
        cout << "Node " << i << " has " << subtree[i] - 1 << " children.\n";
    }
    
    return 0;
}
