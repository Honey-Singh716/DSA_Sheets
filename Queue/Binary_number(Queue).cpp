#include <iostream>
#include <queue>
using namespace std;

vector<int> Binary(int n){

    queue<int> q;
    vector<int> result;

    q.push(1);

    while(n--){
        int temp = q.front();
        q.pop();
        result.push_back(temp);

        q.push(temp * 10);
        q.push(temp * 10 + 1);
    }
    return result;
}


int main(){
    int n = 5;

    vector<int> result = Binary(n);

    for(int i =0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}