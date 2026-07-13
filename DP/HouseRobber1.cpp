#include <iostream>
#include <vector>


using namespace std;

int rob(vector<int>& nums,int st,int end){
    int n = end - st;
    
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return nums[st];
    }

    int prev2 = nums[st];
    int prev1 = max(prev2,nums[st+1]);
    int curr;

    for(int i= st+2;i<end;i++){
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
    
    int money = max(rob(nums,0,n-1),rob(nums,1,n));

    cout<<money<<endl;

    return 0;
}
