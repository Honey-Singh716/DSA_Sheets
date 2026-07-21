#include <bits/stdc++.h>
using namespace std;

void f(int node , vector<int>& parent,vector<vector<int>> &adj){
    
    for(auto child : adj[node]){
                if(parent[child] == -1){
          parent[child] = node;
          f(child,parent,adj);
        }
    }
}


int main(){
    vector<vector<int>> edges = {{1,2},{1,3},{2,4},{4,3}};

    int n = 0;
    for(auto &edge : edges){
        n = max(n, max(edge[0], edge[1]) + 1);
    }
    vector<vector<int>> adj(n);

    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    vector<int> parent(n,-1);

    f(1,parent,adj);

    vector<int> print;
    int node = 3;
    int temp = parent[node];
    while(temp != -1){
        print.push_back(temp);
        temp = parent[temp];
    }


    for(auto p : print){
        cout<<p<<" ";
    }
    return 0;
}