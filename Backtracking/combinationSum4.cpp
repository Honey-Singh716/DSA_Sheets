#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fact(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        return n * fact(n-1);
    }    

    int sames(vector<vector<int>>& ans) {

        int ways = 0;

        for (int i = 0; i < ans.size(); i++) {

            unordered_map<int,int> mp;

            for (int x : ans[i])
                mp[x]++;

            long long denom = 1;

            for (auto &it : mp)
                denom *= fact(it.second);

            ways += fact(ans[i].size()) / denom;
        }

        return ways;
    }


    void dfs(int idx, int target,int n,vector<int>& candidates,vector<int>& nums,vector<vector<int>> & ans){
        if(target == 0){
           ans.push_back(nums);
           return;
        }

        if(idx == n|| target < 0){
            return;
        }
        
        for(int i = idx;i<n;i++){
            nums.push_back(candidates[i]);
            dfs(i,target - candidates[i],n,candidates,nums,ans);
            nums.pop_back(); 
        }
    }

    int combinationSum4(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> ans;
        
        int n = candidates.size();

        dfs(0,target,n,candidates,nums,ans);

        return sames(ans);
    }
};

int main(){
    int n = 4;

    vector<int> candidates = {1, 2, 3};

    int target = 4;

    Solution sol;
    int result = sol.combinationSum4(candidates,target);

    cout << result << endl;

    return 0;
}