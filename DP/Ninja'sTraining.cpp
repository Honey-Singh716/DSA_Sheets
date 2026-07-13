#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Ninja(vector<vector<int>>& nums,int days,int last,vector<vector<int>>& dp){
    
    if(days == 0){
       int maxi = 0;
       for(int i = 0;i<3;i++){
        if(i != last)
            maxi = max(maxi,nums[0][i]);
       }

       return maxi;
    }

    int maxi = 0;

    if(dp[days][last] != -1){
        return dp[days][last];
    }

    for(int i=0;i<3;i++){
        if(i != last){
            int point = nums[days][i] + Ninja(nums,days-1,i,dp);
            maxi = max(maxi,point);
        }
    }

    return dp[days][last] = maxi;
}

int main(){
    vector<vector<int>> nums = {{2,1,3},{3,4,6},{10,1,6},{8,3,7}};
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));

    cout<<Ninja(nums,n-1,3,dp);
    return 0;

}

