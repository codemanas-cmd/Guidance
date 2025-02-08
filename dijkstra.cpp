#include "bits/stdc++.h"
using namespace std;

#define int long long
//notes: 
// used to find shortest path to all nodes from a single source
// graph can be directed or undirected
// only works when weight of graph is positive 
//Time complexity : m logn
// m : no. of edges , n: no. of nodes

const int inf = 1e18 /*some really big value*/;

void dijkstra (vector<vector<pair<int,int>>>&adj, vector<int>&d, int s) {
    // initially each value in d is INF
    // INF is some relatively larger positive value that your real distances 
    // can't have

    d[s] = 0;
    set<pair<int,int>>st; // (distance, node id)
    st.insert({0,s});
    while(st.size()) {
        auto [dist, u] = *st.begin();
        st.erase({dist,u});

        for(auto&[v,w]:adj[u]){
            if(d[v] > dist + w){
                st.erase({d[v],v});
                d[v] = dist + w;
                st.insert({d[v],v});
            }
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<int>d(n+1, inf);

    int source = 1; // or whichever node is your starting point
    dijkstra(adj, d, source);
    
}