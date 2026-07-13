#include<iostream>
#include<string>
#include<stack>

using namespace std;

string infix(string str){
    stack<string> st;

    for(int i=str.size()-1;i>=0;i--){
        if(str[i] >= 'a' && str[i] <= 'z' ||
           str[i] >= 'A' && str[i] <= 'Z' ||
           str[i] >= '0' && str[i] <= '9'){
            st.push(string(1, str[i]));
        }
        else{
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string temp = op1 + str[i] + op2;
            st.push(temp);
        }
    }
    return st.top();
}

string postfix(string str){
    stack<string> st;

    for(int i = str.size() - 1;i>=0;i--){
        if(str[i] >= 'a' && str[i] <= 'z' ||
           str[i] >= 'A' && str[i] <= 'Z' ||
           str[i] >= '0' && str[i] <= '9'){
            st.push(string(1, str[i]));
        }
        else{
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string temp = op1 + op2 + str[i];
            st.push(temp);
        }
    }
    return st.top();
}


int main(){
    string str = "*+AB-CD";

    cout<<infix(str)<<endl;
    cout<<postfix(str)<<endl;
    return 0;
}


