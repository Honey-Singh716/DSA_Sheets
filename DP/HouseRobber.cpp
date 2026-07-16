#include <iostream>
#include <vector>


using namespace std;

int rob(vector<int>& nums){
    int n = nums.size();

    if(n == 1){
        return nums[0];
    }

    int prev2 = nums[0];
    int prev1 = max(prev2,nums[1]);
    int curr;

    for(int i=2;i<n;i++){
        int take = nums[i] + prev2;
        int nottake = prev1; 

        curr = max(take,nottake);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n = 4;
    vector<int> nums = {12,22,13,23};
    
    cout<<rob(nums)<<endl;

    return 0;
}