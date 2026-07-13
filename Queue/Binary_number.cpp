#include<iostream>
#include <vector>

using namespace std;

int main(){
    int n = 4;

    vector<int> result;
    for(int i =1;i<n+1;i++){
        
        int num = i;
        int ans = 0;
        int pow = 1;
        while(num > 0){
            int r  = num%2;
            num = num/2;
            ans = ans + r*pow;
            pow = pow*10;
        }

        result.push_back(ans);
    }

    for(int i =0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}