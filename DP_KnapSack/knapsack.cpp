#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int count(vector<int>& weight,vector<int>& val,int idx,int limit,vector<vector<int>>& dp){
    if(idx == 0){
        if(weight[0] <= limit) return val[0];
        else return 0;
    }

    if(dp[idx][limit] != -1){
        return dp[idx][limit];
    }

    int nottake = count(weight,val,idx-1,limit,dp);
    int take = INT_MIN;

    if(weight[idx] <= limit){
        take = val[idx] + count(weight,val,idx-1,limit-weight[idx],dp);
    }

    dp[idx][limit] = max(take,nottake);
    return dp[idx][limit];
}

int main(){
    vector<int> weight = {2,3,5};
    vector<int> val  = {10,30,20};
    int  limit = 6;

    int n = val.size();
    vector<vector<int>> dp(n,vector<int>(limit+1,-1)); 

    //cout<<count(weight,val,n-1,limit,dp);


    // Tabulation
    
    // vector<int> prev(limit+1,0) , vector<int> curr(limit+1,0)
    
    //1. base case
    for(int i= weight[0];i<=limit;i++)  dp[0][i] = val[0]; // prev[i] = val[0];

    //2.For loop
     
    for(int idx = 1;idx <= n-1;idx++){
        for(int w = 0;w<= limit;w ++){
            int notTake= dp[idx-1][w]; // prev[w]

            int take = INT_MIN;
            if(weight[idx] <= w){
                take = val[idx] + dp[idx-1][w - weight[idx]]; // prev[w-weight[idx]];
            }

            dp[idx][w] = max(take,notTake); //curr[w] = 
            //prev = curr;
        }
    }

    cout<<dp[n-1][limit]; //prev[limit] ;
}