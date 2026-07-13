#include <iostream>
#include <vector>
#include <climits>

using namespace std;


//Time - O(3^N) + O(M) Space - O(N*M) + O(N)
int count(int i,int j,vector<vector<int>>& nums,vector<vector<int>>& dp){
    
    if(j < 0 || j >= nums[0].size()){
           return INT_MIN;
    }

    if(i == 0)  return nums[0][j];

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ld = nums[i][j] + count(i-1,j-1,nums,dp);
    int u = nums[i][j] + count(i-1,j,nums,dp);
    int rd = nums[i][j] + count(i-1,j+1,nums,dp);


    return dp[i][j] = max(u,max(ld,rd));

}

// Time - O(N*M) + O(M)  Space - O(N*M)
int count(vector<vector<int>>& nums,vector<vector<int>>& dp){
    int n = nums.size();
    int m = nums[0].size();


    for(int j = 0;j<m;j++){
        dp[0][j] = nums[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){

            int ld = INT_MIN, rd = INT_MIN, u = INT_MIN;

            if(j-1 >= 0){
                ld = nums[i][j] + dp[i-1][j-1];
            }
            
            if(j+1 < m){
                rd = nums[i][j] + dp[i-1][j+1];
            }

            u = nums[i][j] + dp[i-1][j];

            dp[i][j] = max(u,max(ld,rd));
        }
    }

    int ans = INT_MIN;
    for(int j=0;j<m;j++) ans = max(ans, dp[n-1][j]);
    return ans;

}

int main(){
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    
    int n = nums.size();
    int m = nums[0].size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int max_path = count(n-1,0,nums,dp);
    for(int j=1;j<m;j++){
        max_path = max(max_path,count(n-1,j,nums,dp));
    }

    cout<<max_path;

    return 0;
}