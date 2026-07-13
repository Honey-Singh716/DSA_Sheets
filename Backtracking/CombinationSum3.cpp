#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int idx, int target,int n,vector<int>& candidates,vector<int>& nums,vector<vector<int>> & ans,int k){
        if(target == 0){
            if(nums.size() == k){
               ans.push_back(nums);
            }
            return;
        }
   
        if(idx == n|| target < 0){
            return;
        }
        
        for(int i = idx;i<n;i++){
            nums.push_back(candidates[i]);
            dfs(i+1,target - candidates[i],n,candidates,nums,ans,k);
            nums.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> Candidates = {1,2,3,4,5,6,7,8,9};
        vector<int> nums;
        vector<vector<int>> ans;
        

        dfs(0,n,9,Candidates,nums,ans,k);

        return ans;
    }
};


int main(){
    int k = 3;
    int n = 9;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum3(k,n);

    for(const auto& combination : ans){
        for(int num : combination){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}