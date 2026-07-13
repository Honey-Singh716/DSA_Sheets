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
        return INT_MAX;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int upPath = count(i-1,j,nums,dp);
    int leftPath = count(i,j-1,nums,dp);

    int up = (upPath == INT_MAX) ? INT_MAX : nums[i][j] + upPath;
    int left = (leftPath == INT_MAX) ? INT_MAX : nums[i][j] + leftPath;

    return dp[i][j] = min(up,left);
}

int main(){
    int n = 3;
    int m = 3;

    vector<vector<int>> nums = {{2,4,7},{1,4,2},{6,5,10}};

    vector<vector<int>> dp(n,vector<int>(m,-1));


    cout<<count(n-1,m-1,nums,dp);

    return 0;
}