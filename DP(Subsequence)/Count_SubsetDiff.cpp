#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

ll countWays(int idx,int target,vector<int>& nums,vector<vector<ll>>& dp){
    
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

    ll take = 0;
    if(nums[idx] <= target){
        take = countWays(idx-1,target-nums[idx],nums,dp);
    }
    ll notTake = countWays(idx-1,target,nums,dp);

    return dp[idx][target] = (notTake + take) % mod;
}


int main(){
    vector<int> nums = {2,1,3,5,4};
    int D = 1;
    int n = nums.size();


    int total = 0;
    for(int i=0;i<n;i++) total+= nums[i];
   
    if(total < D || (total -D) % 2 == 1){
        cout<<0<<endl;
        return 0;
    }
    int target = (total - D)/2;

    vector<vector<ll>> dp(n,vector<ll>(target+1,-1));
    
    cout<<countWays(nums.size() -1,target,nums,dp)<<endl;
 

    return 0;
}