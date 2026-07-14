#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int profit;
    // int f(int indx,int buy,int fees,vector<int>& nums,vector<vector<int>>& dp){
    //     if(indx == nums.size())  return 0;

    //     if(dp[indx][buy] != -1)  return dp[indx][buy];

    //     long profit = 0;
    //     if(buy){

    //        profit = max(-nums[indx] + f(indx+1,0,fees,nums,dp), f(indx +1, 1,fees,nums,dp)); 
    //     }

    //     else{
    //        profit = max(nums[indx] - fees + f(indx +1,1,fees,nums,dp),f(indx +1 ,0,fees,nums,dp));
    //     }

    //     return dp[indx][buy] = profit;
    // }

    int maxProfit(vector<int>& prices,int fees) {
        int n = prices.size();

        // vector<vector<int>> dp(n,vector<int>(2,-1));

        vector<int> next(2,0);
        vector<int> curr(2,0);         
        //base case 
        
        for(int i = n-1;i>=0;i--){
            curr[1] = max(-prices[i] + next[0], next[1]); 
            curr[0] = max(prices[i] - fees + next[1],next[0]);
            next = curr;
        }
        return next[1];

       // return f(0,1,fees,prices,dp);
    }

    //we also take four variables like aheadNotBuy ,aheadBuy and currNotbuy , currBuy then swap it...
};