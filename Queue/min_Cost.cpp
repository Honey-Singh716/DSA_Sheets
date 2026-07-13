#include <bits/stdc++.h>

using namespace std;
#define V 5
#define INF INT_MAX

int min_cost(vector<vector<int>>& adj,int u,int sr,int t,bool visited[]){
    

    if(u == t){
        return 0;
    }
   
    int ans = INF;
    visited[u] = 1;


    for(int i =0;i<V;i++){
        if(adj[u][i] != INT_FAST32_MIN && !visited[i]){
            int res = min_cost(adj,i,sr,t,visited);
            
            if(res != INF){
                ans = min(ans,adj[u][i] + res);
            }
        }
    }

    visited[u] = 0;

    return ans;
}