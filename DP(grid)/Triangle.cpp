#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count(int i,int j,vector<vector<int>>& nums,vector<vector<int>>& dp){

    if(i == nums.size() - 1)  return nums[i][j];

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int down = nums[i][j] + count(i+1,j,nums,dp);
    int diag = nums[i][j] + count(i+1,j+1,nums,dp);

    return dp[i][j] = min(down,diag);
}


int count1(vector<vector<int>>& nums,vector<vector<int>>& dp){

    int n = nums.size();
    
    for(int j = 0;j<n;j++){
        dp[n-1][j] = nums[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        for(int j =i;j>=0;j--){

            int down = nums[i][j] + dp[i+1][j];
            int diag = nums[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down,diag);
        }
    }

    return dp[0][0];
}


int main(){
    vector<vector<int>> nums = {{1},{2,3},{4,5,6},{7,8,9,10}};

    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));

    cout<<count(0,0,nums,dp);
    
    return 0;
}