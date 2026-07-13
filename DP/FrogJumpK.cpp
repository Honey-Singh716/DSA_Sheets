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
    int k = 2;
    // vector<int> dp(n, -1);

    // cout << DP(n-1, H, dp);

    vector<int> dp(n,0);

    dp[0] = 0;

    for(int i=1;i<n;i++){
        int min_Cost = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                int cost = dp[i-j] + abs(H[i] - H[i-j]);
                if(cost < min_Cost) min_Cost = cost;
            }
        }
        dp[i] = min_Cost;
    }
    
    cout<<dp[n-1];
}