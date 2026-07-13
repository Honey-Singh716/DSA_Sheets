#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{1,1,0},{0,1,0},{0,1,1}};
    int m = matrix[0].size();


    stack<int> st;
    
    for(int j =0;j<m;j++){
        st.push(j);
        while(st.size() > 1){
            int a = st.top();

            st.pop();

            int b = st.top();
            st.pop();

            if(matrix[a][b] == 1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
    }

    int c = st.top();

    for(int i =0;i<m;i++){
        if(i == c){
            continue;
        }

        if(matrix[i][c] == 0 || matrix[c][i] == 1){
            cout<<"No celebrity"<<endl;
            return 0;
        }
    }
    cout<<"Celebrity is "<<c<<endl;
    return 0;
}