#include <iostream>
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


class stack{
    Node* top;
    int size;


    public:
    stack(){
        top = NULL;
        size = 0;
    }


    void push(int x){
        Node* new_node = new Node(x);

        new_node->next = top;
        top = new_node;
        size++;
    }

    int pop(){
        if(top == NULL){
            cout<<"Stack is underflow"<<endl;
            return -1;
        }
       
        Node* temp = top;
        top = top->next;

        int x = temp->data;
        delete temp;
        size--;

        return x;
    }


    int top_element(){
        if(top == NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return top->data;
    }

    int size_stack(){
        return size;
    }


    bool is_empty(){
        return top == NULL;
    }


};


int main(){
    stack s;

    s.push(10);
    s.push(20);


    cout<<s.top_element()<<endl;


    s.pop();

    cout<<s.top_element()<<endl;

    cout<<s.size_stack()<<endl;

    return 0;
}