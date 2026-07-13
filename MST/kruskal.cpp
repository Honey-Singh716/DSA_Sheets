#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findU(int node,vector<int>& parent){
    if(node == parent[node]) return node;

    return parent[node] = findU(parent[node],parent);
}

int Union(int u,int v,vector<int>& parent,vector<int>& rank){
    int paru = findU(u,parent);
    int parv = findU(v,parent);

    if(rank[paru] < rank[parv]){
        parent[paru] = parv;
    }
    else if(rank[parv] < rank[paru]){
        parent[parv] = paru;
    }
    else{
        parent[parv] = paru;
        rank[paru]++;
    }
}


int MST(vector<vector<int>>& edges,int n,vector<pair<int,int>>& MST){
    vector<int> parent(n);
    vector<int> rank(n,0);

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    sort(edges.begin(),edges.end(),[](vector<int>& a,vector<int>& b){
        return a[0] < b[0];
    });

    int sum = 0;

    for(auto it : edges){
        int wt = it[0];
        int u = it[1];
        int v = it[2];

        if(findU(u,parent) != findU(v,parent)){
            sum += wt;
            MST.push_back({u,v});
            Union(u,v,parent,rank);
        }
    }
    return sum;
}