#include <bits/stdc++.h>
using namespace std;

int LBS(vector<int>& nums){

    int n = nums.size();
    vector<int> lis(n, 1);

    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[prev] < nums[i])
                lis[i] = max(lis[i], lis[prev] + 1);
        }
    }

    vector<int> lds(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int next = n - 1; next > i; next--) {
            if (nums[next] < nums[i])
                lds[i] = max(lds[i], lds[next] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, lis[i] + lds[i] - 1);

    return ans;
}


int main(){
    vector<int> nums = {1,11,2,10,4,5,2,1};

    cout<<LBS(nums);

    return 0;
}