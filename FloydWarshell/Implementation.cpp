#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> shortest(int n,vector<vector<int>>& matrix){
   
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    return matrix;
}


int main(){
    int n = 5;
    vector<vector<int>> matrix;

    shortest(n,matrix);

    return 0;
}