#include <iostream>
#include <vector>

using namespace std;
bool check(int node,vector<int>& color,vector<vector<int>>& adj){
    int c = color[node];

    for(auto it: adj[node]){
        if(color[it] == c){
            return false;
        }
    }

    return true;
}

bool KColor(int node,int n,int m,vector<int>& color,vector<vector<int>>& adj){
    if(node == n){
        return true;
    }

    for(int i = 1;i<=m;i++){
        color[node] = i;
        if(check(node,color,adj)){
            if(KColor(node+1,n,m,color,adj)){
                return true;
            }
        }
        color[node] = 0;
    }
    return true;
}

int main(){
    int n = 4;
    int k = 3;

    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{2,3}};

    vector<vector<int>> adj(n);
    for(auto it : edges){
       int u = it[0];
       int v = it[1];
       
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
 
    vector<int> color(n,0);
    if(KColor(0,n,k,color,adj)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }


    return 0;
}