#include <iostream>
#include <queue>
#include<stack>
#include<vector>

using namespace std;


int reverseK(queue<int>& q,int k){
    if(q.empty() || k <=0 || k > q.size()){
        return -1;
    }

    stack<int> s;

    for(int i =0;i<k;i++){
        s.push(q.front());
        q.pop();
    }


    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i =0;i<q.size() - k;i++){
        q.push(q.front());
        q.pop();
    }


    return 0;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    reverseK(q,k);

    while(!q.empty()){
        cout<<q.front()<<",";
        q.pop();
    }
    cout<<endl;

    return 0;
}