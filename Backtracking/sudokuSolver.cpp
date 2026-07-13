#include <iostream>
#include <vector>

using namespace std;

bool check(int num,int row,int col,vector<vector<int>>& sudo){
    
    for(int i=0;i<9;i++){
        if(sudo[row][i] == num)  return false;
    }

    
    for(int i=0;i<9;i++){
        if(sudo[i][col] == num)  return false;
    }

    int cr = 3*(row/3);
    int cc = 3*(col/3);

    for(int i=cr;i<cr+3;i++){
        for(int j = cc;j<cc+3;j++){
            if(sudo[i][j] == num){
                return false;
            }
        }
    }

    return true;
}


bool solve(int n,vector<vector<int>>& sudo){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sudo[i][j] == -1){
                for(int k=1;k<=9;k++){
                    if(check(k,i,j,sudo)){
                        sudo[i][j] = k;

                        if (solve(n,sudo))
                            return true;

                        sudo[i][j] = -1;
                    }
                }
                return false;
                
            }
        }
        
        
    }
    return true;
}
    
int main() {

    vector<vector<int>> sudo = {
        {5,3,-1,-1,7,-1,-1,-1,-1},
        {6,-1,-1,1,9,5,-1,-1,-1},
        {-1,9,8,-1,-1,-1,-1,6,-1},
        {8,-1,-1,-1,6,-1,-1,-1,3},
        {4,-1,-1,8,-1,3,-1,-1,1},
        {7,-1,-1,-1,2,-1,-1,-1,6},
        {-1,6,-1,-1,-1,-1,2,8,-1},
        {-1,-1,-1,4,1,9,-1,-1,5},
        {-1,-1,-1,-1,8,-1,-1,7,9}
    };

    if (solve(9,sudo)) {

        cout << "Solved Sudoku\n\n";

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {
                cout << sudo[i][j] << " ";
            }

            cout << endl;
        }
    }
    else {
        cout << "No Solution Exists";
    }

    return 0;
}