#include <iostream>
#include <vector>

using namespace std;

void permutation(int idx,vector<int>& nums,vector<vector<int>>& ans,int& k,bool& isk){
    if(idx == nums.size()){
        k--;
        if(k == 0){
           ans.push_back(nums);
           isk = true;

        }
        return;
    }

    if(isk){
        return;
    }

    for(int i = idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        permutation(idx+1,nums,ans,k,isk); 
        swap(nums[idx],nums[i]); 
    }
}


int main(){
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> ans;

    int k = 9;
    bool isk = false;

    permutation(0,nums,ans,k,isk);

    for(auto it: ans){
        for(int i : it){
            cout<<i;
        }
    }

    return 0;
}