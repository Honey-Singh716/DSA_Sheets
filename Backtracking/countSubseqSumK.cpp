#include <iostream>
#include <vector>

using namespace std;

int Count(int idx,int n,vector<int>& nums,int sum ,int k){
    if(idx == n){
        if(sum == k){
            return 1;
        }
        else{
            return 0;
        }
    }


    sum = sum + nums[idx];
    int l = Count(idx+1,n,nums,sum,k);
    sum = sum - nums[idx];
    int r = Count(idx + 1,n,nums,sum,k);

    return l+r;
}

int main(){
    int n = 3;

    vector<int> nums = {1, 2, 3};

    int k = 3;

    int ans = Count(0,n,nums,0,k);

    cout<<ans<<endl;

    return 0;
}