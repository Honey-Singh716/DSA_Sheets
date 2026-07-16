#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int f(int i,vector<int>& nums,int k,vector<int>& dp){
    if(i == nums.size())  return 0;

    int len = 0;
    int MaxAn = INT_MIN;
    int maxi = INT_MIN;
  
    if(dp[i] != -1) return dp[i];


    for(int j = i; j< min((int)nums.size(),i+k); j++){
        len ++;
        maxi = max(maxi ,nums[j]);
        int sum = maxi * len + f(j+1,nums,k,dp);

        MaxAn = max(MaxAn,sum);
    }

    return dp[i] = MaxAn;
}


int main(){
    int k = 3;
    vector<int> nums = {1,15,7,9,2,5,10};

    int n = nums.size();

    vector<int> dp (n+1,-1);

    cout<<f(0,nums,k,dp);

    return 0;
}