#include <iostream>
#include <vector>

using namespace std;
bool ischeck(int row,int col,int n,vector<string>& board){
    int r = row;
    int c = col;

    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q')  return false;
        
        row--;
        col--;
    }


    row = r;
    col = c;

    while(col >= 0){
        if(board[row][col] == 'Q')  return false;

        col--;
    }

    row = r;
    col = c;

    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        row ++;
        col--;
    }


    return true;
    
}

void nQueen(int n,int col,vector<vector<string>>& ans,vector<string>& board){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int i = 0;i<n;i++){
        if(ischeck(i,col,n,board)){
            board[i][col] = 'Q';
            nQueen(n,col+1,ans,board);
            board[i][col] = '.';
        }
    }
}


int main(){
    int n = 4;

    vector<vector<string>> ans;

    vector<string> board(n);

    string S(n,'.');
    for(int i=0;i<n;i++){
        board[i] = S;
    }


    nQueen(n,0,ans,board);

    cout<<ans.size();

    return 0;


}