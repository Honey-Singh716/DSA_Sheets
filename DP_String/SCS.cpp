#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s1 = "brute";
    int n = s1.size();

    string s2 = "groot";
    int m = s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
    
    //tabulation

    for(int j = 0;j<m;j++)  dp[0][j] = 0;
    for(int i=0;i<n;i++)  dp[i][0] = 0;

    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
            
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int len = dp[n][m];


    string s = "";

    int i = n,j = m;
    
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            s += s1[i-1];
            i--;
            j--;
        }

        else if(dp[i-1][j] > dp[i][j-1]){
            s += s1[i-1];
            i = i-1;
        }
        else{
            s += s2[j-1];
            j = j-1;
        }
    }

    while(i > 0){
        s += s1[i-1];
        i--;
    }

    while(j >0){
        s += s2[j-1];
        j--;
    }

    cout<<s<<endl;

    reverse(s.begin(),s.end());

    cout<<s;

}