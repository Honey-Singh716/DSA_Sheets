#include <iostream>
#include <vector>

using namespace std;

bool check(int idx,vector<int>& nums,int target,int& count){
    if(target == 0){
        count++;
        return true;
    }

    if(idx == 0){
        if(target == nums[0]){
            count++;
            return true;
        }
        else{
            return false;
        }
    }


    bool take = check(idx-1,nums,target-nums[idx],count);
    

    bool nottake = check(idx-1,nums,target,count);

    return take || nottake;

}

int main(){
    vector<int> nums = {1,3,2,4,3,2};
    int target = 7;
    int count = 0;
    bool ch = check(nums.size()-1,nums,target,count);
 
    if(ch){
        cout<<"True"<<endl;
        cout<<"Total Number of subsets habing target sum is "<<count<<endl;
    }
    else{
        cout<<"False";
    }


    return 0;
}