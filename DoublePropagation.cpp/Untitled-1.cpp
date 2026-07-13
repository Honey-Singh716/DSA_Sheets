#include <bits/stdc++.h>

using namespace std;

long long maximumSumOfpeaks(vector<int>& heights){
        
    int n = heights.size();

    long long max_num;
    max_num = 0;
    for(int i =0;i <n;i++){
        long long count = 0;
        vector<int> peaks = heights;
        for(int j = i;j<n-1;j++){
              //decreasing;
            if(peaks[j] < peaks[j+1]){
               peaks[j + 1] = peaks[j]; 
            } 
        }
        
        if(i != 0){
            for(int k = i;k>=1;k--){
            //increasing
                if(peaks[k] < peaks[k-1]){
                peaks[k-1] = peaks[k];
                } 
            }
        }
         
        for(auto & it : peaks){
            count += it;
        }
        max_num = max(count,max_num);
    }
        return max_num;
    }


int main(){

    vector<int> peaks = {5,3,4,1,2};
    cout<<maximumSumOfpeaks(peaks);
    return 0;
}