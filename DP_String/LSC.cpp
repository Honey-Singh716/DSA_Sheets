#include <bits/stdc++.h>
using namespace std;

bool compare(string& s1,string & s2){
        if(s1.size() != s2.size() + 1)  return false;

        int first = 0;
        int second = 0;

        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }

            else{
                first++;
            }
        }

        if(second == s2.size()) return true;
        return false;

    }


int main(){
    vector<string> nums = {"a","acb","ab","abcd","abced"};
    int n = nums.size();

    sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });

    vector<int> dps(n,1);
    vector<int> hash(n,0);

    for(int i=0;i<n;i++){
        hash[i] = i;
    }

    int maxi = 1;
    int lastindex = 0;
    for(int i=0;i<n;i++){
        for(int prev = 0;prev < i;prev++){
            if(compare(nums[i],nums[prev]) && (1 + dps[prev]) > dps[i]){
                
                dps[i] = 1 + dps[prev];
                hash[i] = prev;

                if(maxi < dps[i]){
                    maxi = dps[i];
                    lastindex = i;
                }
            }
        }
    }

    cout<< maxi<<endl;
    vector<string> result;
    result.push_back(nums[lastindex]);

    while(lastindex != hash[lastindex]){
        lastindex = hash[lastindex];
        result.push_back(nums[lastindex]);
    }

    reverse(result.begin(), result.end());
    for(const string &s : result) cout << s << " ";
    cout << endl;
}