#include <iostream>
#include <vector>

using namespace std;

int count(int idx,int target,vector<int>& nums,vector<vector<int>>& dp){
    
    if(idx == 0){
        if(target == 0 && nums[0] == 0)  return 2;

        if(target == 0 || nums[0] == target){
            return 1;
        }

        return 0;
    }

    if(dp[idx][target] != -1){
        return dp[idx][target];
    }

    int take = 0;
    if(nums[idx] <= target){
        take = count(idx-1,target-nums[idx],nums,dp);
    }
    int notTake = count(idx-1,target,nums,dp);

    return dp[idx][target] = notTake + take;
}


int main(){
    vector<int> nums = {2,1,3,5,4};
    int target = 6;
    int n = nums.size();

    vector<vector<long long>> dp(n,vector<long long>(target+1,0));
     
    //cout<<count(nums.size() -1,target,nums,dp)<<endl;


    for(int i=0;i<n;i++)  dp[i][0] = 1;
    
    if(nums[0] == 0)
        dp[0][0] = 2;
    else
    {
        dp[0][0] = 1;

        if(nums[0] <= target)
            dp[0][nums[0]] = 1;
    }

    for(int i = 1;i<n;i++){
        for(int j = 1;j<=target;j++){
            
            int notTake = dp[i-1][j];

            int take = 0;
            if(nums[i] <= j){
                take = dp[i-1][j-nums[i]];
            }

            dp[i][j] = notTake + take;
        }
    }

    cout<<dp[n-1][target];



    // 

    return 0;
}