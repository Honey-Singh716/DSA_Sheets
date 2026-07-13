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

        if(c == '+' || c == '-' || c ==  '*' || c == '/'){
            int op2 = stoi(st.top());
            st.pop();

            int op1 = stoi(st.top());
            st.pop();

            if(c == '+'){
                st.push(to_string(op1 + op2));
            }
            else if(c == '-'){
                st.push(to_string(op1 - op2));
            }
            else if(c == '*'){
                st.push(to_string(op1 * op2));
            }
            else{
                st.push(to_string(op1 / op2));
            }
        }

        else{
            st.push(string(1, c));
        }
    }
    cout<<st.top()<<endl;
}