#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,string& a,string & b,vector<vector<int>>& dp){
    if(i == 0) return j;
    if(j == 0)  return i;

    if(dp[i][j] != -1) return dp[i][j];
    
    
    if(a[i-1] == b[j-1]){
        return dp[i][j] = f(i-1,j-1,a,b,dp);
    }

    else{
        int in = f(i,j-1,a,b,dp);
        int rem = f(i-1,j,a,b,dp);
        int rep = f(i-1,j-1,a,b,dp);

        return dp[i][j] = 1 + min(in,min(rem,rep));
    }
}

int main(){
    string a = "horse";
    string b = "ros";
  
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
    cout<<"Recursion: " <<f(n,m,a,b,dp)<<endl;

    //tabulation

    vector<vector<int>> dp1(n+1,vector<int>(m+1,0));

    //base case


    for(int i=0;i<=n;i++)  dp1[i][0] = i;
    for(int j = 0;j<=m;j++)  dp1[0][j] = j;

    //for loop

    for(int i=1;i<=n;i++){
        for(int j= 1;j<=m;j++){
            if(a[i-1] == b[j-1]){
               dp1[i][j] = dp1[i-1][j-1];
            }

            else{
                int in = dp1[i][j-1];
                int rem = dp1[i-1][j];
                int rep = dp1[i-1][j-1];

                dp1[i][j] = 1 + min(in,min(rem,rep));
            }
        }
    }


    cout<<"Tabulation : "<<dp1[n][m];

    return 0;
}