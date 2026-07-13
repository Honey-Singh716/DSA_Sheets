#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{1,1,0},
                                 {0,1,0},
                                 {0,1,1}};
    
    int m = matrix[0].size();

    int i =0;
    int j = m-1;


    while(i <j){
        if(matrix[i][j] == 1){
            i++;
        }
        else{
            j--;
        }
    }


    int c = i;

    for(int k = 0;k<m;k++){
        if(k == c){
            continue;
        }

        if(matrix[k][c] == 0 || matrix[c][k] == 1){
            cout<<"No celebrity"<<endl;
            return 0;
        }
    }


    cout<<"celebrity is "<<c<<endl;
    return 0;
}