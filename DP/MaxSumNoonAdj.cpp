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
    int n = 4;
    vector<int> dp(n,-1);
    
    vector<int> nums = {1,3,2,4};
        
    cout<<f(n-1,nums,dp);
    
    //tabulation

    vector<int> dps(n,0);

    dps[0] = nums[0];

    int prev2 = max(0,nums[0]);
    int prev1 = max(prev2,nums[1]);

    for(int i=2;i<n;i++){
        int take = nums[i];
        if(i > 1) take += prev2;

        int nottake = prev1;

        int curr = max(take,nottake);

        prev2 = prev1;
        prev1 = curr;
    }
     
    cout<<endl;
    cout<<prev1;

    return 0;
}
