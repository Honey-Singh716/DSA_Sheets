#include<iostream>
#include<string>
#include <stack>
using namespace std;

int main(){
    stack<string> st;
    
    string str = "*+AB-CD";


    for(int i = str.size() - 1;i>=0;i--){
        char c = str[i];
        
        if(c >= 'a' && c <= 'z' ||
           c >='A' && c <= 'Z' ||
           c >= '0' && c <= '9'){
            st.push(string(1, c));
        }
        else{
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string temp = op1 + c + op2;
            
            st.push(temp);
        }
        
        
    }
    cout<<st.top()<<endl;

    return 0;


}