#include <iostream>
using namespace std;


class stack
{
    int top;
    int *arr;
    int capacity;


public:
    stack(int cap){
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x){
        if(top == capacity - 1){
            cout<<"Stack is overflow"<<endl;
        }
        else{
            top++;
            arr[top] = x;
        }
    }

    int pop(){
        if(top == -1){
            cout<<"Stack is underflow"<<endl;
            return -1;
        }
        else{
            top --;
            return arr[top + 1];
        }
    }

    int top_element(){
        if(top == -1){
            cout<<"Stack is underflow"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }


    int size(){
        return top + 1;
    }

    bool is_empty(){
        return top == -1;
    }

    bool is_full(){
        return top == capacity-1;
    }
    


};


int main() {
    stack st(4);

    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // popping one element
    cout << "Popped: " << st.pop() << "\n";

    // checking top element
    cout << "Top element: " << st.top_element() << "\n";

    // checking if stack is empty
    cout << "Is stack empty: " << (st.is_empty() ? "Yes" : "No") << "\n";

    // checking if stack is full
    cout << "Is stack full: " << (st.is_full() ? "Yes" : "No") << "\n";

    return 0;
}