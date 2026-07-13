#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int idx, vector<int>& nums, int target,
           vector<vector<int>>& dp)
{
    if(target == 0)
        return true;

    if(idx == 0)
        return nums[0] == target;

    if(dp[idx][target] != -1)
        return dp[idx][target];

    bool take = false;

    if(target >= nums[idx])
        take = check(idx-1, nums, target-nums[idx], dp);

    bool notTake = check(idx-1, nums, target, dp);

    return dp[idx][target] = take || notTake;
}

void printSubset(int idx,
                 int target,
                 vector<int>& nums,
                 vector<vector<int>>& dp,
                 vector<int>& ans)
{
    while(idx > 0 && target > 0)
    {
        // If target can still be achieved without nums[idx],
        // don't take it.
        if(check(idx-1, nums, target, dp))
        {
            idx--;
        }
        else
        {
            ans.push_back(nums[idx]);
            target -= nums[idx];
            idx--;
        }
    }

    if(target != 0)
        ans.push_back(nums[0]);

    reverse(ans.begin(), ans.end());
}

int main()
{
    vector<int> nums = {1,3,2,4,3,1};

    int n = nums.size();

    int total = 0;

    for(int x : nums)
        total += x;

    if(total % 2)
    {
        cout << "Partition not possible\n";
        return 0;
    }

    int target = total / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    if(check(n-1, nums, target, dp))
    {
        cout << "Partition Possible\n\n";

        vector<int> subset;

        printSubset(n-1, target, nums, dp, subset);

        cout << "Subset 1 : ";

        int sum = 0;

        for(int x : subset)
        {
            cout << x << " ";
            sum += x;
        }

        cout << "\nSum = " << sum << endl;
    }
    else
    {
        cout << "Partition not possible\n";
    }

    return 0;
}