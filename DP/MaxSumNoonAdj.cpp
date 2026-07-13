#include <iostream>
#include <vector>

using namespace std;

int f(int idx,vector<int>& nums,vector<int>& dp){
    if(idx == 0) return nums[idx];
    if(idx < 0)  return 0;
 
    if(dp[idx] != -1){
        return dp[idx];
    }

    int pick = nums[idx] + f(idx-2,nums,dp);
    int notpick = f(idx-1,nums,dp);

    return dp[idx] = max(pick,notpick);
}

int main(){
    int n = 3;
    vector<int> dp(n,-1);
    
    vector<int> nums = {1,2,4};
        
    cout<<f(n-1,nums,dp);

    return 0;
}
