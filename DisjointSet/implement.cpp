#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
     vector<int> rank,parent;

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUpar(parent[node]);
    }

    void UnionByRank(int u,int v){
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);

        if(upar_u == upar_v) return;
        if(rank[upar_u] < rank[upar_v]){
            parent[upar_u] = upar_v;
        }
        else if(rank[upar_v] < rank[upar_u]){
            parent[upar_v] = upar_u;
        }
        else{
            parent[upar_v] = upar_u;
            rank[upar_u]++;
        }
    }
};


int main(){
    DisjointSet ds(7);

    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    
    if(ds.findUpar(4) == ds.findUpar(3)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }

    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);

    if(ds.findUpar(5) == ds.findUpar(4)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }

    return 0;
}