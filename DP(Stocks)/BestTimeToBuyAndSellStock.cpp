#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prefixMin(prices.size());

        prefixMin[0] = prices[0];

        for(int i=1;i<prices.size();i++){
            prefixMin[i] = min(prefixMin[i-1],prices[i]);
        }

        int maxProfit = INT_MIN;
        for(int i=0;i<prices.size();i++){
            maxProfit = max((prices[i] - prefixMin[i]),maxProfit);
        }

        return maxProfit;
    }
};