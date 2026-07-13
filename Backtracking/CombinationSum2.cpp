#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(int idx,int n,int target,vector<int>& nums,vector<int>& candidates,vector<vector<int>>& ans){
        
        if(target == 0){
            ans.push_back(nums);
            return;
        }
        
        if(idx == n || target < 0){
            return;
        }


        for(int i = idx; i < n; i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
            nums.push_back(candidates[i]);  
            dfs(i+1,n,target - candidates[i],nums,candidates,ans);
            nums.pop_back();
       }


    }
 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> ans;

        int n = candidates.size();

        sort(candidates.begin(),candidates.end());
        
        dfs(0,n,target,nums,candidates,ans);

        return ans;
    }
};

int main(){
    int n = 4;

    vector<int> candidates = {10,1,2,7,6,1,5};

    int target = 8;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(candidates,target);

    for(const auto& combination : ans){
        for(int num : combination){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}