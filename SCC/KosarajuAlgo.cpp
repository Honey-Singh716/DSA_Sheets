#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node,vector<int>& vis,vector<int> adj[],stack<int>& st){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}

void dfs2(int node,vector<int>& vis,vector<int> trans[]){
    vis[node] = 1;

    for(auto it: trans[node]){
        if(!vis[it]){
            dfs2(it,vis,trans);
        }
    }
}


int kosaraju(int v, vector <int> adj[]){
    vector<int> vis(v,0);
    stack<int> st;
    //O(v + E)
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }


    vector<int> trans[v];
    //O(V+E)
    for(int i=0;i<v;i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            trans[it].push_back(i);
        }
    }


    int scc = 0;
    //O(V+E)
    while(!st.empty()){
        int node = st.top();

        st.pop();

        if(!vis[node]){
            scc++;
            dfs2(node,vis,trans);
        }
    }

    return scc;

}
