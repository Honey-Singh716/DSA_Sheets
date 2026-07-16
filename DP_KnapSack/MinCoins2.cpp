#include <bits/stdc++.h>
using namespace std;

int ways(int idx, int target, vector<int>& coins, vector<vector<int>>& dp){

    if(idx == 0){
        return (target % coins[0] == 0);
    }

    if(dp[idx][target] != -1)
        return dp[idx][target];

    int notTake = ways(idx-1, target, coins, dp);

    int take = 0;
    if(coins[idx] <= target)
        take = ways(idx, target-coins[idx], coins, dp);

    return dp[idx][target] = take + notTake;
}

int main(){

    vector<int> coins = {1,2,3};
    int target = 4;

    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(target+1,-1));

    cout << ways(n-1,target,coins,dp);
}