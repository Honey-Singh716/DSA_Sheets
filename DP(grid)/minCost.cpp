#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//time - O(2^(n+m)) and space O(n+m) for the recursive solution below.

int count(int i,int j,vector<vector<int>>& nums,vector<vector<int>>& dp){
    if(i == 0 && j == 0){
        return nums[0][0];
    }

    if(i < 0 || j < 0){
        return 1e9;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int upPath = nums[i][j] + count(i-1,j,nums,dp);
    int leftPath = nums[i][j] + count(i,j-1,nums,dp);

    return dp[i][j] = min(upPath,leftPath);
}

int main(){
    int n = 3;
    int m = 3;

    vector<vector<int>> nums = {{2,4,7},{1,4,2},{6,5,10}};

    vector<vector<int>> dp(n,vector<int>(m,-1));


    cout<<count(n-1,m-1,nums,dp);

    return 0;
}