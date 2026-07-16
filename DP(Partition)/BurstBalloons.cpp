#include <bits/stdc++.h>

using namespace std;

int coins(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
    if(i > j)  return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int maxi = -1e9;
    for(int k = i;k<=j;k++){
        int cost = nums[i-1]*nums[k]*nums[j+1] + coins(i,k-1,nums,dp) + coins(k+1,j,nums,dp);

        maxi = max(maxi ,cost);
    }

    return dp[i][j] = maxi;
}


int main(){
    vector<int> nums = {3,1,5,8};
    
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);


    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<coins(1,n,nums,dp)<<endl;
    


    //tabulation
    vector<vector<int>> dps(n+2,vector<int>(n+2,0));
    
    for(int i=n;i>=1;i--){
        for(int j = 1;j<=n;j++){
            if(i > j) continue;
            int maxi = INT_MIN;

            for(int k = i;k<=j;k++){
               int cost = nums[i-1]*nums[k]*nums[j+1] + dps[i][k-1] + dps[k+1][j];
               maxi = max(maxi ,cost);
            }

            dps[i][j] = maxi;
        }
    }

    cout<<dps[1][n];
}

