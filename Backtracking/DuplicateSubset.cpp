#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int count(vector<int>& nums){
    unordered_map<int,int> mp;

    for(auto & el : nums){
        mp[el]++;
    }

    int count = 1;
    for(auto & m : mp){
        count *= (m.second + 1);
    }
    return count;
}


int main(){
    vector<int> nums = {1,2,2,3};

    cout<<count(nums)<<endl;

    return 0;
}