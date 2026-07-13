#include<iostream>
#include<string>
#include<stack>

using namespace std;


int main(){
    stack<string> st;

    string str;
    cin>>str;


    for(int i =0;i<str.size();i++){
        char c = str[i];

        if(c >= 'a' && c <= 'z' ||
           c >= 'A' && c <= 'Z' ||
           c >= '0' && c <= '9'){
            st.push(string(1, c));
        }
        else{
            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }
    }
    cout<<st.top()<<endl;
}