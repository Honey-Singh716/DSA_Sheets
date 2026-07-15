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
 
    int n = nums.size();

    vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));

    cout<<MCM(1,nums.size()-1,nums,dp)<<endl;
    
    int dps[n][n];

    for(int i=0;i<n;i++){
        dps[i][i] = 0;
    }

    
    for(int i=n-1;i>=1;i--){
        for(int j= i+1;j<n;j++){
            int mini = 1e9;
            for(int k = i;k<j;k++){
                int steps = nums[i-1]*nums[k]*nums[j] + dps[i][k] + dps[k+1][j];

                mini= min(mini ,steps);
            }
            dps[i][j] = mini;
        }
    }


    cout<<dps[1][n-1];

    return 0;
}