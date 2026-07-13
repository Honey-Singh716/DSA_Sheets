#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

string firstNonRepeating(string A){
    string ans = "";
    queue<char> q;

    unordered_map<char,int> mp;

    for(int i =0;i<A.size();i++){
        char ch = A[i];

        mp[ch]++;

        if(mp[ch] == 1){
            q.push(ch);
            ans += q.front();
        }

        else{
            while(!q.empty() && mp[q.front()] > 1){
                q.pop();
            }

            ans += q.empty()? '#' : q.front();
        }

    }
    return ans;
}

int main() {
    string A = "aabc";
    cout<<firstNonRepeating(A)<<endl;


    return 0;
}