#include <iostream>
#include <vector>

using namespace std;

int counts(int n,int target,vector<int>& nums){
    
    vector<int> dp(target+1,0);
    dp[0] = 1;

    for(int sum = 1;sum <= target;sum++){
        for(int i = 0;i<n;i++){
            if(sum - nums[i] >= 0){
                dp[sum] += dp[sum - nums[i]];
            }
        }
    }
    return dp[target];
}


int main(){
    int n = 3;
    vector<int> nums = {1,2,3};

    int target = 4;

    cout<<counts(n,target,nums)<<endl;

    return 0;
}