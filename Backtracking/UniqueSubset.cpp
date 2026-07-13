#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int idx,
             vector<int>& nums,
             vector<int>& path,
             vector<vector<int>>& ans) {

        ans.push_back(path);

        for(int i = idx; i < nums.size(); i++) {

            // Skip duplicates
            if(i > idx && nums[i] == nums[i-1])
                continue;

            path.push_back(nums[i]);

            dfs(i + 1, nums, path, ans);

            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> path;

        dfs(0, nums, path, ans);

        cout<<"Size of subsets array are : " << ans.size() << endl;

        return ans;
    }
};


int main() {
    vector<int> nums = {1, 2, 2};

    Solution sol;
    vector<vector<int>> ans = sol.subsetsWithDup(nums);

    for(const auto& subset : ans) {
        for(int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}