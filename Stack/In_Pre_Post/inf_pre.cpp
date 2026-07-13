#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    stack<string> st;
    stack<char> op;

    string str;
    cin>>str;

    string temp;


    for(int i =0;i<str.size();i++){
        char c = str[i];

        if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/'){
            op.push(c);
        }

        else if(c == ')'){
            while(!op.empty() && op.top() != '('){
                string op2 = st.top();
                st.pop();

                string op1 = st.top();
                st.pop();

                char oper = op.top();
                op.pop();

                temp = string(1, oper) + op1 + op2;
                st.push(temp);
                temp = "";
            }
            op.pop(); // Pop the '('
        }
        else{
            st.push(string(1, c));
        }

        
    }

    temp = " ";
    while(!op.empty()){
        string op2 = st.top();
        st.pop();

        string op1 = st.top();
        st.pop();

        char oper = op.top();
        op.pop();

        temp = string(1, oper) + op1 + op2;
        st.push(temp);
        temp = "";
    }

    cout<<st.top()<<endl;

    return 0;
}