#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int knight(int x, int y,int dx, int dy, int n){
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

        vector<pair<int,int>> moves = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

        for(auto move: moves){
            int newX = i + move.first;
            int newY = j + move.second;

            if(newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY]){
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

    int x = 1;
    int y = 3;

    int dx = 5;
    int dy = 0;

    cout<<knight(x,y,dx,dy,n)<<endl;

    return 0;
}