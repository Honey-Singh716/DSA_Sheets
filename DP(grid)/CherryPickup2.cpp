#include <bits/stdc++.h>

using namespace std;

int cherry(int i,int j1,int j2,vector<vector<int>>& board){
    
    if(j1 >= board[0].size() || j1 < 0 || j2 >= board[0].size() || j2 < 0){
        return -1e9;
    }
    
    if(i == board.size()-1){
        if(j1 == j2) return board[i][j1];
        else  return board[i][j1] + board[i][j2];
    }

    
    int maxi = INT_MIN;
    for(int dj1 = 1;dj1>=-1;dj1--){
        for(int dj2 = 1;dj2>= -1;dj2--){
            int take;
            if(j1 == j2){
               take = board[i][j1] + cherry(i+1,j1+dj1,j2+dj2,board);
            }

            else{
                take = board[i][j1] + board[i][j2] + cherry(i+1,j1+dj1,j2+dj2,board);
            }

            maxi = max(take,maxi);
        }
    }
    return maxi;
}


int main(){
    vector<vector<int>> board = {{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    int n = board.size();
    int m = board[0].size();

    cout<<cherry(0,0,m-1,board);

    return 0;
}