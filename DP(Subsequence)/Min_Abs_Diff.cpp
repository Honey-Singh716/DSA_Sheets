#include <iostream>
#include <vector>

using namespace std;

int minSubsetDiff(vector<int>& arr, int n)
{
    int total = 0;

    for(int x : arr)
        total += x;

    vector<vector<bool>> dp(n, vector<bool>(total + 1, false));

    for(int i=0;i<n;i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=total;target++)
        {
            bool notTake = dp[i-1][target];

            bool take = false;

            if(arr[i] <= target)
                take = dp[i-1][target-arr[i]];

            dp[i][target] = take || notTake;
        }
    }

    int ans = INT_MAX;

    for(int s1=0;s1<=total/2;s1++)
    {
        if(dp[n-1][s1])
        {
            int s2 = total - s1;
            ans = min(ans, abs(s1-s2));
        }
    }

    return ans;
}