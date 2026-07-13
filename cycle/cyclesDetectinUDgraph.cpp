#include <iostream>
#include <vector>

using namespace std;

bool isCycle(int node,int parent,vector<int>& vis,vector<int> adj[]){
    vis[node] =1;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(isCycle(it,node,vis,adj))  return true;
        }

        else if(it != parent){
            return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n,0);
    // space complexity - O(N) + O(N) + O(N);
    //time complexity - O(V+ 2E) + O(N)
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(isCycle(i,-1,vis,adj)){
                cout<<"Cycle is present"<<endl;
                return 0;
            }
        }
    }

    cout<<"Cycle is not present"<<endl;

    return 0;
}