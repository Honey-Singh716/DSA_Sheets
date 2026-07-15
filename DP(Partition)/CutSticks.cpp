#include <bits/stdc++.h>

using namespace std;

int f(int i,int j, vector<int>& nums,vector<vector<int>>& dp){
    if(i > j) return 0;

    int cost;
    int mini = 1e9;

    if(dp[i][j] != -1)  return dp[i][j];

    for(int k = i;k <= j;k++){
        cost = nums[j+1] - nums[i-1] + f(i,k-1,nums,dp) + f(k+1,j,nums,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}

int main(){

    vector<int> nums = {1,3,5,4};
    int c = nums.size();
    int n = 7;

    nums.push_back(n);
    nums.insert(nums.begin(),0);

    sort(nums.begin(),nums.end());

    vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
    
    cout<<f(1,c,nums,dp)<<endl;


    vector<vector<int>> dps(c+2,vector<int>(c+2,0));
    
    for(int i= c;i>=1;i--){
        for(int j = 1;j<=c;j++){
            
              if(i > j) continue;
              int mini = 1e9;
            
              for(int k = i;k <= j;k++){
                int cost = nums[j+1] - nums[i-1] + dps[i][k-1] + dps[k+1][j];
                mini = min(mini,cost);
              }
              dps[i][j] = mini;
        }
    }

    cout<<dps[1][c];


    return 0;
}