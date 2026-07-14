#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // int profit;
    // int f(int indx,int buy,vector<int>& nums,vector<vector<int>>& dp){
    //     if(indx == nums.size())  return 0;

    //     if(dp[indx][buy] != -1)  return dp[indx][buy];

    //     long profit = 0;
    //     if(buy){

    //        profit = max(-nums[indx] + f(indx+1,0,nums,dp), f(indx +1, 1,nums,dp)); 
    //     }

    //     else{
    //        profit = max(nums[indx] + f(indx +1,1,nums,dp),f(indx +1 ,0,nums,dp));
    //     }

    //     return dp[indx][buy] = profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> next(2,0);
        vector<int> curr(2,0);         
        //base case 

        next[0] = 0;
        next[1] = 0;

        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                long profit = 0;
                if(buy){

                    profit = max(-prices[i] + next[0], next[1]); 
                }

                else{
                    profit = max(prices[i] + next[1],next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

    //we also take four variables like aheadNotBuy ,aheadBuy and currNotbuy , currBuy then swap it...
};