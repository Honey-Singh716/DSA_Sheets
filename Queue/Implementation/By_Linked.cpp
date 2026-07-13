#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Queue{
    
    Node* front;
    Node* rear;

    int size;

    public:
    Queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }


    void push(int x){
        Node* temp = new Node(x);

        if(front == NULL){
            front = temp;
            rear = temp;
            size++;
        }
        else{
            rear->next = temp;
            rear = temp;
            size++;
        }

    }

    void pop(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        delete temp;
        size--;
    }

    int getFront(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return front->data;
    }

    int getRear(){
        if(rear == NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return rear->data;
    }

    int size_(){
        return size;
    }
};


int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.size_()<<endl;

    q.pop();

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.size_()<<endl;

    return 0;
}