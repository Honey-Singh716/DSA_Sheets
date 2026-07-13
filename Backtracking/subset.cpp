#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int idx ,vector<vector<int>>& arr,vector<int>& nums,vector<int>& path,int n,vector<int>& subsetSum,int sum){

    if(idx >= n){
        arr.push_back(path);
        subsetSum.push_back(sum);
        return;
    }
    

    sum += nums[idx];
    path.push_back(nums[idx]);
    dfs(idx+1,arr,nums,path,n,subsetSum,sum);

    path.pop_back();
    sum -= nums[idx];

    dfs(idx + 1, arr, nums, path, n, subsetSum, sum);

}

int main(){
    int n = 3;

    vector<int> nums = {1, 2,3};
    vector<vector<int>> arr;
    vector<int> path;
    vector<int> subsetSum;

    dfs(0, arr, nums, path, n, subsetSum, 0);

    for(const auto& subseq : arr){
        for(int num : subseq){
            cout << num << " ";
        }
        cout << endl;
    }

    sort(subsetSum.begin(), subsetSum.end());

    cout << "Subset sums are: ";
    for(int sum : subsetSum){
        cout << sum << " ";
    }
    cout << endl;

    cout << "Size of subsets array are : " << arr.size() << endl;
    return 0;
}