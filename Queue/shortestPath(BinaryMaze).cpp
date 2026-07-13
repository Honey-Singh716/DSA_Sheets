#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int knight(int x, int y,int dx, int dy, vector<vector<int>>& binary){
    int n = binary.size();
    if(x < 0 || x >= n || y < 0 || y >= n || dx < 0 || dx >= n || dy < 0 || dy >= n){
        return -1;
    }

    if(x == dx && y == dy){
        return 0;
    }
    
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> visited(n,vector<int>(n,0));
    q.push({{x,y},0});

    visited[x][y] = 1;

    while(!q.empty()){
        pair<pair<int,int>,int> temp = q.front();
        q.pop();

        int i = temp.first.first;
        int j = temp.first.second;
        int distance = temp.second;

        vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};

        for(auto move: moves){
            int newX = i + move.first;
            int newY = j + move.second;

            if(newX >= 0 && newX < n && newY >= 0 && newY < n && binary[newX][newY] == 1 && !visited[newX][newY]){
                if(newX == dx && newY == dy){
                    return distance + 1;
                }
                
                visited[newX][newY] = 1;
                q.push({{newX,newY},distance + 1});
            }
        }
    }

    return -1;
}

int main(){
    int n = 6;

    int x = 0;
    int y = 1;

    int dx = 2;
    int dy = 2;

    vector<vector<int>> binary = {{1, 1, 1, 1},{1, 1, 0, 1},{1, 1, 1, 1},{1, 1, 0, 0},{1, 0, 0, 1}};

    cout<<knight(x,y,dx,dy,binary)<<endl;

    return 0;
}