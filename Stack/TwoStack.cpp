#include<iostream>
#include<vector>

using namespace std;

class TwoStack{
    vector<int> arr;
    int top1 = -1;
    int top2 = -1;
    int n;

    public:

    TwoStack(int size){
        n = size;
        arr.resize(n);

        top2 = n;

    }


    void push1(int x){
        if(top1 < top2-1){
            top1++;
            arr[top1] = x;
        }

        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void push2(int x){
        if(top1 < top2 -1){
            top2--;
            arr[top2] = x;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }


    void pop1(){
        if(top1 >= 0){
            top1--;
        }

        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    void pop2(){
        if(top2 < n){
            top2++;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }


    int peek1(){
        if(top1 >= 0){
            return arr[top1];
        }

        else{
            cout<<"Stack underflow"<<endl;
            return -1;
        }
    }


    int peek2(){
        if(top2 < n){
            return arr[top2];
        }

        else{
            cout<<"Stack underflow"<<endl;
            return -1;
        }
    }


    int size_(){
        return top1 + 1 + n - top2;
    }

};

int main(){
    TwoStack s(5);

    s.push1(1);
    s.push2(2);
    s.push1(3);
    s.push2(4);
    s.push1(5);

    cout<<s.peek1()<<endl;
    cout<<s.peek2()<<endl;
    cout<<s.size_()<<endl;
}