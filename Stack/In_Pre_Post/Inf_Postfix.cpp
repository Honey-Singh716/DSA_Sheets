#include<iostream>
#include<string>
#include<stack>

using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}



int main(){
    stack<char> op;
    string s = "";

    string str;
    cin>>str;

    for(int i =0;i<str.size();i++){
        char c = str[i];

        if((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9')){
            s += c;
        }
        else{
        

            if(c == '('){
                op.push(c);
            }

            else if(c == ')'){
                while(!op.empty() && op.top() != '('){
                    s += op.top();
                    op.pop();
                }
                if(!op.empty()) op.pop();
            }

            else{
                while(!op.empty() && (
                    prec(op.top()) > prec(c) ||
                    (prec(op.top()) == prec(c) && c != '^')
                )){
                    s+= op.top();
                    op.pop();
                }
                op.push(c);
            }
        }
    }

    while(!op.empty()){
        s += op.top();
        op.pop();
    }
    
    cout<<s<<endl;
    
}