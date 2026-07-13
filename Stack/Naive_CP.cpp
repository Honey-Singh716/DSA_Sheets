#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{1,1,0},
                                 {0,1,0},
                                 {0,1,1}};

    int m = matrix[0].size();
    
    int j = 0;
    int isceleb = 1;
    int celebrity = -1;

    while(j < m){
        for(int i =0;i<m;i++){
            if(i == j){
                continue;
            }

            if(matrix[i][j] == 0 || matrix[j][i] == 1){
                isceleb = 0;
                break;
            }
        }
        if(isceleb == 1){
            celebrity = j;
            break;
        }
        j++;
        isceleb = 1;
    }
    cout<<celebrity<<endl;
    return 0;
}