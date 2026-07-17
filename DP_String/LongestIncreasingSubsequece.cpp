#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
    if(i == nums.size()) return 0;

    if(dp[i][prev + 1] != -1) return dp[i][prev+1]; 

    // not take
    int len = f(i+1,prev,nums,dp);

    //take

    if(prev == -1 || nums[i] > nums[prev]){
        len = max(len , 1 + f(i+1,i,nums,dp));
    }

    return dp[i][prev+1] = len;

}


int main(){
    vector<int> nums = {5,4,11,1,16,8};
    int n = nums.size();
    
    vector<vector<int>> dp(n,vector<int>(n+1,-1));

    vector<int> dps(n,1);
    vector<int> hash(n,0);

    for(int i=0;i<n;i++){
        hash[i] = i;
    }

    int maxi = 1;
    int lastindex = 0;
    for(int i=0;i<n;i++){
        for(int prev = 0;prev < i;prev++){
            if(nums[prev] < nums[i] && (1 + dps[prev]) > dps[i]){
                
                dps[i] = 1 + dps[prev];
                hash[i] = prev;

                if(maxi < dps[i]){
                    maxi = dps[i];
                    lastindex = i;
                }
            }
        }
    }

    cout<< maxi<<endl;
    //cout<<f(0,-1,nums,dp);

    int result[maxi];
  
    cout<<nums[lastindex]<<" ";
    result[0] = nums[lastindex];

    int index = 0;
    while(lastindex != hash[lastindex]){
        lastindex = hash[lastindex];
        cout<<nums[lastindex]<<" ";
        result[index++] = nums[lastindex];
    }

    return 0;
}