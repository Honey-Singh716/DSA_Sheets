#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;   

    public:
    Queue(int cap){
        capacity = cap;
        arr = new int [cap];
        size = 0;
        front = 0;
        rear = 0;
    }

    void push(int x){
        if(size == capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        rear = (front + size) % capacity;
        arr[rear] = x;
        size++;

    }

    void pop(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return;
        }

        front = (front+1)%capacity;
        size--;
    }

    int getFront(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return arr[front];

    }

    int getRear(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return arr[rear];
    }

    int size_(){
        return size;
    }
};


int main(){
    Queue q(5);


    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.pop();
    cout<<q.getFront()<<endl;
    
    q.push(6);

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    return 0;
}
