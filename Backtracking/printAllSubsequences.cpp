#include <iostream>
#include <vector>

using namespace std;

void dfs(int idx,vector<vector<int>>& arr,vector<int>& nums,vector<int>& path,int n,int sum,int k){
    if(sum == k){
        arr.push_back({path});
        return;
    }
    
    if(idx >= n){
        return;
    }


    path.push_back(nums[idx]);
    sum = sum + nums[idx];
    dfs(idx + 1, arr, nums, path, n,sum, k);
    path.pop_back();
    sum = sum - nums[idx];
    dfs(idx + 1, arr, nums, path, n,sum, k);
}

int main(){
    int n = 3;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> arr;
    vector<int> path;

    dfs(0, arr, nums, path, n, 0, 3);

    for(const auto& subseq : arr){
        for(int num : subseq){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}