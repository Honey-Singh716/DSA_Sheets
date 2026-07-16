#include <bits/stdc++.h>

using namespace std;

int Rod(int i,int len,vector<int>& nums,vector<vector<int>>& dp){
    if(i == 0){
        return nums[0]*len;
    }
   
    if(dp[i][len] != -1) return dp[i][len];

    int nottake = Rod(i-1,len,nums,dp);
    int take = INT_MAX;
    if(i+1 <= len){
        take = nums[i] + Rod(i,len-i-1,nums,dp);
    }

    return dp[i][len] = min(take,nottake);
}

int main(){
    vector<int> nums = {1,5,2,7,3};

    int len = 7;
    int n = nums.size();

    vector<vector<int>> dp(n,vector<int>(len+1,-1));

    cout<<Rod(n-1,len,nums,dp);

    return 0;
}