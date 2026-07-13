#include<iostream>
#include<stack>

using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;

    public:

    void push(int x){
        s1.push(x);
    }

    void pop(){
        if(s2.empty()){
            while(!s1.empty()){
                int a = s1.top();
                s1.pop();
                s2.push(a);
            }
        }

        s2.pop();
    }


    int top(){
        if(s2.empty()){
            while(!s1.empty()){
                int a = s1.top();
                s1.pop();
                s2.push(a);
            }
        }

        return s2.top();
    }

    int size_(){
        return s1.size() + s2.size();
    }



};


int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.pop();
    cout<< q.top() <<endl;
    q.push(3);

    cout << q.size_() << endl;
}