#include<iostream>
#include<string>
#include <algorithm>
#include<vector>

using namespace std;

bool ispalindrome(string word,int start,int end){
    string temp = word;
    reverse(temp.begin()+start ,temp.end()+end);
    return temp == word;
}


void dfs(string word,int start,vector<string>&path,vector<vector<string>>& matrix){
    if(start == word.size()){
        matrix.push_back(path);
        return;
    }

    for(int i = start;i<word.size();i++){
        if(ispalindrome(word,start,i)){
            path.push_back(word.substr(start,i-start + 1));
            dfs(word,i+1,path,matrix);
            path.pop_back();
        }
    }
}

int main() {
    string word = "aab";
    vector<string> path;
    vector<vector<string>> matrix;
    dfs(word,0,path,matrix);

    for(auto & it : matrix){
        for(auto & it1 : it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    return 0;
}