#include <bits/stdc++.h>
using namespace std;


bool f(int i,int j,string& s1,string & s2,vector<vector<int>>& dp){
    
    if(i == 0 && j == 0) return true;
    if(i == 0 && j > 0) return false;
    if(j == 0){
        for(int k = 0; k < i; k++){
            if(s1[k] != '*'){
                return false;
            }
        }

        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];


    if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
         return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    }

    if(s1[i-1] == '*'){
        return dp[i][j] = f(i,j-1,s1,s2,dp) || f(i-1,j,s1,s2,dp);
    }

    return dp[i][j] = false;
}

int main(){
    string s1 = "*ab?d";
    string s2 = "dabcd";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    if(f(n,m,s1,s2,dp)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    

    return 0;
}