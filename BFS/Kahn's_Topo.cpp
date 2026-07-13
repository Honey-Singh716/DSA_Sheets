#include <iostream>
#include<vector>
#include <queue>


using namespace std;

int topo(int n ,vector<vector<int>>& relations){
    vector<vector<int>> adj(n);

    for(auto& rel : relations){
        adj[rel[0]].push_back(rel[1]);
    }

    vector<int> indegree(n,0);

    for(int i =0;i<n;i++){
        for(auto& neigh : adj[i]){
            indegree[neigh]++;
        }
    }
    
    queue<int> q;

    for(int i =0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    

    int visited_nodes = 0;
    int steps = 0;
    while(!q.empty()){
        int size = q.size();
        steps ++;

        while(size--){
            int node = q.front();
            q.pop();

            visited_nodes++;

            for(auto& neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }

        }
        
    }

    return visited_nodes == n ? steps : -1;
}


int main(){
    int n = 4;
    vector<vector<int>> relations = {{1,0},{2,0},{3,1},{2,3}};

    cout<<topo(n,relations)<<endl;

    return 0;
}