#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// int DP(int idx, vector<int>& H, vector<int>& dp){

//     if(idx == 0) return 0;
    
//     if(dp[idx] != -1){
//         return dp[idx];
//     }

//     int left = DP(idx-1,H,dp) + abs(H[idx] - H[idx-1]);
//     int right = INT_MAX;

//     if(idx > 1){
//         right = DP(idx-2, H, dp) + abs(H[idx] - H[idx-2]);
//     }
//     return dp[idx] = min(left,right);
// }


int main(){
    vector<int> H = {10,20,30,10,30,20};
    int n = H.size();
    // vector<int> dp(n, -1);

    // cout << DP(n-1, H, dp);

    vector<int> dp(n,0);

    dp[0] = 0;

    for(int i=1;i<n;i++){
        int l = dp[i-1] + abs(H[i] - H[i-1]);
        int r = INT_MAX;

        if(i > 1){
            r = dp[i-2] + abs(H[i] - H[i-2]);
        }
        dp[i] = min(l,r);
    }
    
    cout<<dp[n-1];
}