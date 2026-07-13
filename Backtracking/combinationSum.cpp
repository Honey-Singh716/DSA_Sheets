#include <iostream>
#include <vector>
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

       nums.push_back(candidates[idx]);  

        
       dfs(idx,n,target - candidates[idx],nums,candidates,ans);
      
       nums.pop_back();
        
       dfs(idx+1,n,target,nums,candidates,ans);
    }
 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> ans;

        int n = candidates.size();

        dfs(0,n,target,nums,candidates,ans);

        return ans;
    }
};


int main(){
    
    int n = 4;

    vector<int> candidates = {2,3,6,7};

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