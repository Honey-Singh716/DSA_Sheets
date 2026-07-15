#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(int idx,
               vector<int>& nums,
               vector<int>& bucket,
               int target)
    {

        if(idx==nums.size())
            return true;

        for(int i=0;i<bucket.size();i++)
        {

            if(bucket[i]+nums[idx]>target)
                continue;

            bucket[i]+=nums[idx];

            if(solve(idx+1,nums,bucket,target))
                return true;

            bucket[i]-=nums[idx];

            // pruning
            if(bucket[i]==0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum=0;

        for(int x:nums)
            sum+=x;

        if(sum%k)
            return false;

        int target=sum/k;

        sort(nums.rbegin(),nums.rend());

        if(nums[0]>target)
            return false;

        vector<int> bucket(k,0);

        return solve(0,nums,bucket,target);
    }
};