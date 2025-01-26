#include "bits/stdc++.h"
using namespace std;

#define int long long

int32_t main (){

    int x;
    vector<int>v ={1,2,3,4};

    auto help = [&] (/*parameters*/) -> void /*return type*/ {
        // [&] means you have access to all outer scope variables (like x, v) by reference.
        // This is useful when you want to modify the outer variables inside the lambda.

        /*code comes here*/
        cout << 2 * v[0] << "\n";

    }; /*dont forget this semi colon*/

    /*you can call this help function anywhere below now*/
    help();

    /*notice how you did'nt have to pass v as a parameter*/

    /*this really helps when you write recursive dfs like this*/

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1);
    auto dfs = [&] (auto&&self, int u) -> void {
        /*
            you have access to -> adj, vis, n, m
            auto&&self -> have to be passed when writing a recursive lambda
        */
        vis[u] = true;
        for(auto&v:adj[u]){
            if(!vis[v])
                /*
                    inside itself refer lambda function by self
                */
                self(self,v);
        }

    };

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            /*
            anywhere outside the lambda function it's called by its name
            */
            dfs(dfs,i);
        }
    }

}