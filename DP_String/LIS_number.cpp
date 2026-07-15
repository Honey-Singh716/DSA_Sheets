#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums = {1,3,5,4,7};
    int n = nums.size();
    
    vector<int> dps(n,1);
    vector<int> count(n,1);

    int maxi = 1;
    for(int i=0;i<n;i++){
        for(int prev = 0;prev < i;prev++){

            if(nums[i] > nums[prev] && (1 + dps[prev]) > dps[i]){
                dps[i] = 1 + dps[prev];
                count[i] = count[prev];
            }

            else if(nums[i] > nums[prev] && (1 + dps[prev]) == dps[i]){
                count[i] += count[prev];
            }
        }

        maxi = max(dps[i],maxi);
    }


    int ans = 1;
    for(int i=0;i<n;i++){
        if(dps[i] == maxi){
          ans = max(ans,count[i]);
        }
    }

    cout<<ans;

    return 0;
}
