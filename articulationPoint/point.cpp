#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<int> & vis, int tin[], int low [], vector<int> adj [],vector<int> &mark,int & timer){
    vis[node] = 1;
    low[node] = tin[node] = timer;
    timer ++;
 
    int child = 0;
    for(auto it : adj[node]){
        if(it == parent) continue;

        if(!vis[it]){
            dfs(it,node,vis,tin,low,adj,mark,timer);
            low[node] = min(low[node],low[it]);
            child++;

            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
        }
        else{
            low[node] = min(low[node],tin[it]);
        }
    }
    if(parent == -1 && child > 1){
        mark[node] = 1;
    }
}

vector<int> articulationPoint(int n,vector<int> adj[]){
    vector<int> vis(n,0);
    int timer = 0;
    int tin[n], low[n];
    vector<int> mark(n,0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i,-1,vis,tin,low,adj,mark,timer);
        }
    }

    vector<int> res;
    for(int i = 0; i < n; i++){
        if(mark[i]) res.push_back(i);
    }
    return res;
}