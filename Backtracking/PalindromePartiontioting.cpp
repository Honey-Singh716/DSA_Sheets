#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(string& word,int start,int end){
    string temp = word;

    reverse(temp.begin() + start,temp.begin() + end + 1);

    if(temp == word)  return true;

    return false;
}

void partition(int n,string& word,int start,vector<string>& path,vector<vector<string>>& ans){
    
    if(start == n){
       ans.push_back(path);
       return;  
    }

    for(int i=start;i<n;i++){

        if(isPalindrome(word,start,i)){
           string temp = word.substr(start,i-start + 1);
           path.push_back(temp);
           partition(n,word,i+1,path,ans);
           path.pop_back();
        }
    }
}

int main(){
    string word = "aabbaa";
    int n = word.size();

    vector<string> path;
    vector<vector<string>> ans;

    partition(n,word,0,path,ans);

    for(int i=0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}