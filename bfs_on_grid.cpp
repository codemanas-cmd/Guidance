#include <bits/stdc++.h>
using namespace std;
#define int long long

// Performs BFS on a grid and returns the distance from start to target.
// Returns -1 if the target is unreachable.
// 'grid' is a vector of strings where '#' denotes an obstacle,
// 'S' is the starting cell and 'T' is the target.
int bfsGrid(int n, int m, const vector<string>& grid, pair<int,int> start, pair<int,int> target) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    dist[start.first][start.second] = 0;
    q.push(start);
    // Directions: down, up, right, left.
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(x == target.first && y == target.second)
            return dist[x][y];
        for(auto &dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
    
    pair<int,int> start, target;
    // Find the coordinates of 'S' and 'T' in the grid.
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(grid[i][j] == 'S') start = {i, j};
            if(grid[i][j] == 'T') target = {i, j};
        }
    }
    
    int ans = bfsGrid(n, m, grid, start, target);
    cout << ans << "\n";
    return 0;
}
