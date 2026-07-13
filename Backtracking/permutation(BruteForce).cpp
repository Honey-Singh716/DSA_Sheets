#include <iostream>

#include <vector>
using namespace std;

void perm(int n,vector<int>& nums,vector<vector<int>>& ans,vector<int> & path,vector<bool> & visited){
      if(path.size() == n){
        ans.push_back(path);
        return;
      }


      for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            path.push_back(nums[i]);

            perm(n,nums,ans,path,visited);

            path.pop_back();
            visited[i] = false;
        }
      }
}

int main(){
    int n = 3;
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> visited(n,false);

    perm(n,nums,ans,path,visited);

    for(const auto& perm : ans){
        for(int num : perm){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}