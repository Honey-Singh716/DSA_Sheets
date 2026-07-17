#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,string& a,string& b,vector<vector<int>>& dp){
    if(j == 0)  return 1;
    if(i == 0)  return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    if(a[i-1] == b[j-1]){
        int take = f(i-1,j-1,a,b,dp);
        int nottake = f(i-1,j,a,b,dp);

        return dp[i][j] = take + nottake;
    }

    else{
        return dp[i][j] = f(i-1,j,a,b,dp);
    }
}

int main(){
    string a = "babgbag";
    string b = "bag";
    
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));

    cout<<"Recursion : " << f(a.size(),b.size(),a,b,dp)<<endl;


    //tabulation
     //1.base case

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp1(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++)  dp1[i][0] = 1;
    for(int j=1;j<=m;j++)  dp1[0][j] = 0;

    //for loop

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){

            if(a[i-1] == b[j-1]){
                int take = dp1[i-1][j-1];
                int nottake = dp1[i-1][j];

                dp1[i][j] = take + nottake;
            }

            else{
                dp1[i][j] = dp1[i-1][j];
            }
        }
    }

    cout<<"Tabulation : "<<dp1[n][m];


    return 0;
}