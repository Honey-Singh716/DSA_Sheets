#include<iostream>
#include<string>
#include<vector>

using namespace std;

void dfs(int start, string &s){

    if(start == s.size())
        return;

    string temp = "";

    for(int end = start; end < s.size(); end++){

        temp += s[end];

        cout << temp << endl;   // current substring

        dfs(end + 1, s);
    }
}


int main() {
    string word = "abc";

    dfs(0, word);

    return 0;
}