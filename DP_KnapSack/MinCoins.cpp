#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coin(int idx,int target,vector<int>& nums,vector<vector<int>>& dp){
    if(idx ==0){
        if(target%nums[0] == 0){
            return target/nums[0];
        }

        else return 1e9;
    }

    if(dp[idx][target] != -1){
        return dp[idx][target];
    }
     
    int notTake = coin(idx-1,target,nums,dp);
    int take = 1e9;

    if(nums[idx] <= target){
        take = 1 + coin(idx,target-nums[idx],nums,dp);
    }

    return dp[idx][target] = min(take,notTake);
}

int main(){
    vector<int> nums = {1,2,3};
    int target = 17;
     
    int n = nums.size();

    vector<vector<int>> dp(n,vector<int>(target+1,-1));

    int ans  = coin(n-1,target,nums,dp);

    if(ans >= 1e9){
        cout<<"-1";
    }

    else{
        cout<<ans<<endl;
    }



    //Tabulation
    vector<vector<int>> dps(n,vector<int>(target+1,0));
    
    for(int t = 0;t<=target;t++){
        if(t%nums[0] == 0) dps[0][t] = t/nums[0];
        else dps[0][t] = 1e9;
    }

    for(int ind = 1;ind<=n-1;ind++){
        for(int T = 0;T<=target;T++){

            int notTake = dps[ind-1][T];
            int take = 1e9;
            if(nums[ind] <= T) {
                take = 1 + dps[ind][T-nums[ind]];
            }

            dps[ind][T] = min(take,notTake);
        }
    }

    cout<<dps[n-1][target];

}