#include <iostream>
#include <vector>

using namespace std;

//time - O(n*m) and space(n- 1 + m -1) + O(n*m);

int count(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& board){
    if(i < 0 || j < 0){
        return 0;
    }

    if(board[i][j] == -1){
        return 0;
    }

    if(i == 0 && j == 0){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = count(i-1,j,dp,board);
    int left = count(i,j-1,dp,board);

    return dp[i][j] = up + left;
}

int main(){
    int n = 3;
    int m = 3;

    vector<vector<int>> board = {{0,0,0},{0,-1,0},{0,0,0}};

    vector<vector<int>> dp(n,vector<int>(m,-1));

    cout<<count(n-1,m-1,dp,board);

    return 0;
}