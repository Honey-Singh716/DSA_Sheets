#include <iostream>
#include <vector>

using namespace std;

void permutation(int idx,vector<int>& nums,vector<vector<int>>& ans){
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        permutation(idx+1,nums,ans);
        swap(nums[idx],nums[i]); 
    }
}


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;

    permutation(0,nums,ans);

    for(const auto& perm : ans){
        for(int num : perm){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}