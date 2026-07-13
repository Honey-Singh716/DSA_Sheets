#include<bits/stdc++.h>
using namespace std;


int dfs(vector<vector<int>>& adj,int  parent,int node){
      cout<< node << " ";

      for(auto it : adj[node]){
        if(it == parent){
            continue;
        }
        dfs(adj,node,it);
      }
}



int main(){
    int n = 5; // number of nodes
    vector<vector<int>> adj(n);

    // Adding edges to the adjacency list
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    cout << "DFS Traversal: ";
    dfs(adj, -1, 0); // Start DFS from node 0 with no parent

    return 0;
}

