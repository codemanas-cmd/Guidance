#include "bits/stdc++.h"
using namespace std;

#define int long long

// Define a large constant to represent "infinity" (no path).
// It should be larger than any possible path sum in your graph.
const int inf = 1e18; 

/*
   Floyd Warshall Algorithm:
   -------------------------
   - Purpose: Finds the shortest paths between all pairs of nodes in a graph.
   - Graph Type: Can be applied to both directed and undirected graphs.
   - Edge Weights: Works with negative edge weights provided there are no negative cycles.
   - Time Complexity: O(n^3), where n is the number of nodes.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Read the number of nodes (n) and edges (m).
    int n, m;
    cin >> n >> m;
    
    // Create a distance matrix for the graph.
    // The graph is assumed to be 1-indexed, so we create an (n+1) x (n+1) matrix.
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, inf));
    
    // Initialize the distance from each node to itself as 0.
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    
    // Read each edge and update the distance matrix.
    // Since the graph is undirected, update both (a, b) and (b, a).
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        // In case of multiple edges between the same nodes, we take the minimum weight.
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);
    }
    
    // Run Floyd Warshall to compute the shortest distances between all pairs of nodes.
    // k: Intermediate node, i: Source node, j: Destination node.
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // Only update if the intermediate paths are valid (not INF)
                if (dist[i][k] < inf && dist[k][j] < inf) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Output the shortest distances between every pair of nodes.
    // If no path exists between a pair, "INF" is printed.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == inf)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
