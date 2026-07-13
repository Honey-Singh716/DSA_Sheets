#include <iostream>
#include <vector>
#include<queue>

using namespace std;

int No_ways(vector<vector<int>>& adj,int sr,int dest,int k){
    if(sr == dest && k == 0){
        return 1;
    }

    if(k == 0){
        return 0;
    }

    int count = 0;
    for(int i =0;i<adj.size();i++){
        if(adj[sr][i] == 1){
            count +=  No_ways(adj,i,dest,k-1);
        }
    }

    return count;

}

int main(){
    vector<vector<int>> adj = {
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    int ways = No_ways(adj,0,3,2);
    cout<<ways<<endl;

    return 0;
}