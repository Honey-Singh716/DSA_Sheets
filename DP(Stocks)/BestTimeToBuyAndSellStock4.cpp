#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int f(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
       
    //     if(cap == 0) return 0;
    //     if(i == prices.size())  return 0;

    //     if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

    //     long profit = 0;
    //     if(buy){
    //       profit = max(-prices[i] + f(i+1,0,cap,prices,dp),f(i+1,1,cap,prices,dp));
    //     }

    //     else{
    //         profit = max(prices[i] + f(i+1,1,cap-1,prices,dp),f(i+1,0,cap,prices,dp));
    //     }

    //     return dp[i][buy][cap] = profit;
    // }

    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));


        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<=k;cap++){

                    long profit = 0;
                    if(buy){
                        curr[buy][cap] = max(-prices[i] + after[0][cap],after[1][cap]);
                    }

                    else{
                        curr[buy][cap] = max(prices[i] + after[1][cap-1],after[0][cap]);
                    }
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};