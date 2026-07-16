#include <bits/stdc++.h>

using namespace std;

bool palind(int i, int j, string &str){
    while(i < j){
        if(str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int f(int i,string &str){
    if(i==str.size()) return 0;


    int minCost = INT_MAX;
    for(int k = i;k<str.size();k++){

       if(palind(i,k,str)){
        int cost = 1 + f(k+1,str);
        minCost = min(minCost,cost);
       }
    }


    return minCost;
}


int main(){
    string str = "abbabcba";

    cout<<f(0,str) -1 ;

    //tabulation

    int n = str.size();
    vector<int> dp(n+1,0);

    dp[n] = 0; //base case

    for(int i=n-1;i>=0;i--){
        int minCost = INT_MAX;
        for(int j= i;j<n;j++){
            if(palind(i,j,str)){
                int cost = 1 + dp[j+1];
                minCost = min(minCost,cost);
            }
        }
        dp[i] = minCost;
    }
    cout<<endl;
    cout<<dp[0] - 1;
}