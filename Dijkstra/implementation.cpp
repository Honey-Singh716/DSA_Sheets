#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n,vector<vector<pair<int,int>>>& adj,int src){

    vector<int> dist(n,INT_MAX);

    dist[src] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  

    pq.push({0,src});

    while(!pq.empty()){
        auto [distance,node] = pq.top();
        pq.pop();

        if(distance != dist[node]){
            continue;
        }

        for(auto & [next,wt]: adj[node]){
            if(distance + wt < dist[next]){
                dist[next] = distance + wt;
                pq.push({dist[next],next});
            }
        }
    }
    return dist;
}

int main(){
    
    vector<vector<int>> edges = {{0,1,4},{0,2,1},{2,1,2},{1,3,1},{2,3,5}};

    vector<vector<pair<int,int>>> adj(edges.size());

    for(auto & edge : edges){
        int u,v,wt;
        u = edge[0];
        v = edge[1];
        wt = edge[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    int src;
    cin>>src;

    vector<int> dist = dijkstra(edges.size(),adj,src);

    for(int i=0;i<edges.size();i++){
        cout<<dist[i]<<" ";
    }
}