#include <iostream>
#include <vector>
#include <string>

using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void path(int x,int y,int n,int m, vector<vector<int>>& Maze,vector<char>& paths,vector<vector<char>>& ans){
    if(x == n-1 && y == m-1){
        ans.push_back(paths);
        return;
    }
    
    if(Maze[x][y] != 1){
        return;
    }
    
    for(int k = 0;k<4;k++){
        int newx = x + dx[k];
        int newy = y + dy[k];
        
        if(newx < 0 || newx >= n || newy < 0 || newy >= m){
            continue;
        }

        if(k == 0){
            paths.push_back('U');
        }
        
        if(k == 1){
            paths.push_back('D');
        }
        
        if(k == 2){
            paths.push_back('L');
        }
        
        if(k == 3){
            paths.push_back('R');
        }

        Maze[x][y] = 0;
        path(newx,newy,n,m,Maze,paths,ans);
        Maze[x][y] = 1;
        paths.pop_back();
        
    }
}



int main(){
    int n = 4;
    int m = 4;

    vector<vector<int>> Maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    vector<char> paths;
    vector<vector<char>> ans;

    path(0,0,n,m,Maze,paths,ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
