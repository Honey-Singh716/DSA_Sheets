#include <bits/stdc++.h>
 

using namespace std;

long long f(int i,int j ,int istrue,string &exp,vector<vector<vector<long long>>>& dp){
    const long long mod = 1000000007LL;

    if(i > j) return 0;
    if(i == j){
        if(istrue == 1) return exp[i] == 'T';
        else return exp[i] == 'F';
    }


    if(dp[i][j][istrue] != -1) return dp[i][j][istrue];

    long long ways = 0;
    for(int idx = i+1;idx<=j-1;idx+=2){
       long long LT = f(i,idx-1,1,exp,dp);
       long long LF = f(i,idx-1,0,exp,dp);
       long long RT = f(idx+1,j,1,exp,dp);
       long long RF = f(idx+1,j,0,exp,dp);


       if(exp[idx] == '&'){
        if(istrue)  ways = (ways + (RT*LT)%mod)%mod;
        else ways = (ways + (RT*LF)%mod + (RF * LT)%mod + (RF * LF)%mod)%mod;
       }

       else if(exp[idx] == '|'){
        if(istrue) ways = (ways + (RT*LT)%mod + (RT*LF)%mod + (RF*LT)%mod)%mod;
        else ways = (ways + (RF*LF)%mod)%mod;
       }

       else{
        if(istrue)  ways = (ways + (RT*LF)%mod + (RF*LT)%mod)%mod;
        else  ways = (ways + (RT*LT)%mod + (RF*LF)%mod)%mod;
       }
    }
    return dp[i][j][istrue] = ways;
}


int main(){
    string exp = "T|F&T";
    
    int n = exp.size();
    vector<vector<vector<long long>>>dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));

    cout<<f(0, n-1, 1, exp, dp);
}