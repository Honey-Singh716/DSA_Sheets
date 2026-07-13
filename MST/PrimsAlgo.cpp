#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<pair<int,int>> MST(vector<vector<pair<int,int>>>& adj,int n,vector<pair<int,int>>& MST){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    vector<int> visited(n,0);

    pq.push({0,{0,-1}});
    
    int sum = 0;

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;

        pq.pop();
        
        if(visited[node]) continue;

        visited[node] = 1;

        if(parent != -1){
            MST.push_back({parent,node});
            sum += wt;
        }
        
        for(auto it : adj[node]){
            int adjNode = it.first;
            int edgewt = it.second;
            
            if(!visited[adjNode]){
                pq.push({edgewt,{adjNode,node}});
            }
        } 
    }
    return MST;
}


int main(){
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    // Add edges to the adjacency list
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    vector<pair<int,int>> mstEdges;
    
    MST(adj,n,mstEdges);

    cout << "Edges in the Minimum Spanning Tree:\n";
    for(auto edge : mstEdges){
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
