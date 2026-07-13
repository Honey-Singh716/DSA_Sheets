#include <iostream>
#include <vector>

using namespace std;


int main(){
    string s1 = "abcd";
    int n = s1.size();

    string s2 = "acde";
    int m = s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
    
    //tabulation

    for(int j = 0;j<m;j++)  dp[0][j] = 0;
    for(int i=0;i<n;i++)  dp[i][0] = 0;
  
    int ans = 0;

    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    
    cout<<ans;

}