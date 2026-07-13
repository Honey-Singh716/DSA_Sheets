#include <iostream>
#include <vector>
#include<queue>

using namespace std;

void mod_adj(vector<vector<int>>& adj){
    vector<pair<int, int>> store;
    for(int i =0;i<adj.size();i++){
        for(int j =0;j<adj[0].size();j++){
            if(adj[i][j] == 0){
                store.push_back({i,j});
            }
        }
    }

    vector<pair<int, int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &p : store){
            int i = p.first;
            int j = p.second;
        for(auto move: moves){
            int newX = i + move.first;
            int newY = j + move.second;

            if(newX >= 0 && newX < adj.size() && newY >= 0 && newY < adj.size() && adj[newX][newY] == 1){
                adj[newX][newY] = 0;
            }
        }
    }
}


int min_safePath(vector<vector<int>>& safe){
    vector<vector<int>> visited(
        safe.size(),
        vector<int>(safe[0].size(),0)
    );


    mod_adj(safe);
    queue<pair<pair<int,int>,int>> q;
    
    for(int i =0;i<safe.size();i++){
        if(safe[i][0] != 0){
            q.push({{i,0},1});
            visited[i][0] = 1;
        }
    }
    
    vector<pair<int, int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int sum = q.front().second;
        
        q.pop();

        if(col == safe[0].size() - 1){
            return sum;
        }

        for(auto move : moves){
            int new_row = row + move.first;
            int new_col = col + move.second;

            if(new_row >= 0 && new_row < safe.size() && new_col >= 0 && new_col < safe[0].size() && safe[new_row][new_col] == 1 && visited[new_row][new_col] != 1){
                visited[new_row][new_col] = 1;
                q.push({{new_row, new_col}, sum + 1});
            }
        }
    }
    return -1;
}


int main(){
    int n = 6;

    vector<vector<int>> safe = {{1, 0, 1, 1,1},{1, 1, 1, 1,1},{1, 1, 1, 1,1},{1, 1, 1, 0,1},{1, 1, 1, 1,0}};


    for(int i = 0;i<safe.size();i++){
        for(int j = 0;j<safe[0].size();j++){
            cout<<safe[i][j]<<" ";
        }
        cout<<'\n';
    }

    cout<<min_safePath(safe)<<endl;
}