#include <iostream>
#include <vector>
using namespace std;

void dfs(int node,int parent,vector<int>& vis,int low [],vector<int> adj[],int tin [],int& timer,vector<vector<int>>& bridges){
    vis[node] = 1;
    low[node] = tin[node] = ++timer;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,node,vis,low,adj,tin,timer,bridges);
            low[node] = min(low[node],low[it]);
         
            if(low[it] > tin[node]){
                bridges.push_back({node,it});
            }

        }
        else if(it != parent){
            low[node] = min(low[node],tin[it]);
        }
    }
}


int tarjan(int n,vector<vector<int>>& connections){
    vector<int> adj[n];

    // space - O(v + 2E) + O(3N)
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n,0);
    int low[n];
    int tin[n];

    vector<vector<int>> bridges;
    int timer =0;
   
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,low,adj,tin,timer,bridges);
        }
    }

    return bridges.size();
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> connections;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        connections.push_back({u,v});
    }

    cout<<tarjan(n,connections)<<endl;
}