#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int profit;
    // int f(int indx,int buy,vector<int>& nums,vector<vector<int>>& dp){
    //     if(indx >= nums.size())  return 0;

    //     if(dp[indx][buy] != -1)  return dp[indx][buy];

    //     long profit = 0;
    //     if(buy){

    //        profit = max(-nums[indx] + f(indx+1,0,nums,dp), f(indx +1, 1,nums,dp)); 
    //     }

    //     else{
    //        profit = max(nums[indx] + f(indx + 2,1,nums,dp),f(indx + 1 ,0,nums,dp));
    //     }

    //     return dp[indx][buy] = profit;
    // }

    int maxProfit(vector<int>& prices) { 
        int n = prices.size();

        vector<vector<int>> dp(n+2,vector<int>(2,0)); // use front2 ,front 1, curr

        for(int i = n-1;i>=0;i--){
            dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i] + dp[i+2][1],dp[i+1][0]); 
        }

        return dp[0][1];

       // return f(0,1,prices,dp);
    }
};