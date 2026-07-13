#include <iostream>
#include <stack>

using namespace std;

class Queue{
    public:

    stack<int> st1;
    stack<int> st2;
    int size;

    Queue(){
        size = 0;
    }

    void enqueue(int x){
        st1.push(x);
        size++;
    }


    void dequeue(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        st2.pop();
        size--;

    }

    int peek(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
       

        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int topElement = st2.top();
        return topElement;

    }


    int size_(){
        return size;
    }
};


int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<q.peek()<<endl; // Output: 1

    q.dequeue();

    cout<<q.peek()<<endl; // Output: 2

    return 0;
}