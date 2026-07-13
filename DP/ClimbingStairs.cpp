#include <iostream>
#include <vector>
using namespace std;

int DP(int n,vector<int>& dp){
    if(n == 0)  return 1;
    if(n == 1)  return 1;

    if(dp[n] != -1){
        return dp[n];
    }

    int left = DP(n-1,dp);
    int right = DP(n-2,dp);

    return dp[n] = left + right;
}


int main(){

    int n = 3;

    vector<int> dp(n+1,-1);

    cout<<DP(n,dp);

    return 0;

}