#include <iostream>
#include <vector>

using namespace std;

int f(int i,int j,string &s1 , string & s2,vector<vector<int>>& dp){
    if(i == 0 || j == 0){
        return 0;
    }

    if(dp[i][j] != -1)  return dp[i][j];

    if(s1[i-1] == s2[j-1])  return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);

    return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
}

int main(){
    string s1 = "abcd";
    int n = s1.size();

    string s2 = "acde";
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
    for(int i =0;i<len;i++){
        s += '$';
    }

    int i = n,j = m;
    int index = len-1;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            s[index] = s1[i-1];
            index --;
            i--;
            j--;
        }

        else if(dp[i-1][j] > dp[i][j-1]){
            i = i-1;
        }
        else{
            j = j-1;
        }
    }

    cout<<s<<endl;


    cout<<f(n,m,s1,s2,dp);

    return 0;

}