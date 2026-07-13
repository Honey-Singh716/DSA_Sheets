#include<iostream>
using namespace std;


class Deque{
    int *arr;
    int front;
    int rear;
    int capacity;

    public:
    Deque(int cap){
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = 0;
    }

    ~Deque(){
        delete[] arr;
    }

    bool is_full(){
        return (rear+1)%capacity == front;
    }
    bool is_empty(){
        return front == -1;
    }

    void insert_front(int x){
        if(is_full()){
            cout<<"Deque is overflow"<<endl;
            return;
        }

        if(is_empty()){
            front = rear = 0;
        }
        else{
            front = (front-1 + capacity) % capacity;
        }

        arr[front] = x;
    }

    void insert_rear(int x){
        if(is_full()){
            cout<<"Deque is overflow"<<endl;
            return;
        }
        if(is_empty()){
            front = rear = 0;
        }
        else{
            rear = (rear + 1)%capacity;
        }

        arr[rear] = x;
    }

    int delete_front(){
        if(is_empty()){
            cout<<"Deque is underflow"<<endl;
            return -1;
        }
        
        int x = arr[front];

        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%capacity;
        }
        return x;
    }
    
    int delete_rear(){
        if(is_empty()){
            cout<<"Deque is underflow"<<endl;
            return -1;
        }

        int x = arr[rear];

        if(front == rear){
            front = rear = -1;
        }

        else{
            rear = (rear - 1 + capacity)%capacity;
        }
        return x;
    }
    
    int get_element(int index){
        if(is_empty()){
            cout<<"Deque is underflow"<<endl;
            return -1;
        }
        if(index < 0 || index >= size()){
            cout<<"Index out of bounds"<<endl;
            return -1;
        }
        return arr[(front + index)%capacity];
    }

    int size(){
        if(is_empty()){
            return 0;
        }
        else if(rear >= front){
            return rear - front + 1;
        }
        else{
            return capacity - (front - rear - 1);
        }
    }


    void display(){
        if(is_empty()){
            cout<<"Deque is empty"<<endl;
            return;
        }
        else{
            for(int i =0;i<size();i++){
                cout<<get_element(i)<<" ";
            }
            cout<<endl;
        }
    }

};


int main(){
    Deque dq(5);

    dq.insert_rear(1);
    dq.insert_rear(2);
    dq.insert_front(3);

    for (int i = 0; i < dq.size(); i++){
        cout<<dq.get_element(i)<<endl;
    }

    cout<<dq.size()<<endl;

    return 0;

}