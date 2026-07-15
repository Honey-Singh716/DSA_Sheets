#include <bits/stdc++.h>
using namespace std;

int MCM(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
    if(i == j) return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int mini = 1e9;
    for(int k = i;k<=j-1;k++){
        int steps = nums[i-1]*nums[k]*nums[j] + MCM(i,k,nums,dp) + MCM(k+1,j,nums,dp);  
        mini = min(mini,steps);
    }


    return dp[i][j] = mini;
}



int main(){
    vector<int> nums = {1,2,3,4,5};

    vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));

    cout<<MCM(1,nums.size()-1,nums,dp);

    return 0;
}