#include <iostream>
#include <vector>

using namespace std;

int findU(int node,vector<int>& parent){
    if(node == parent[node]) return node;

    return parent[node] = findU(parent[node],parent);
}

void Union(int u,int v,vector<int>& parent,vector<int>& rank){
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


int provinces(vector<vector<int>>& connections){
    int n = connections.size();

    vector<int> parent(n);
    vector<int> rank(n,0);

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(connections[i][j] == 1){
                if(findU(i,parent) != findU(j,parent)){
                    Union(i,j,parent,rank);
                }
            }
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(parent[i] == i) count++;
    }

    return count;
}


int main(){
    int n = 3;
    vector<vector<int>> connections = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    cout << provinces(connections) << endl;

    return 0;
}