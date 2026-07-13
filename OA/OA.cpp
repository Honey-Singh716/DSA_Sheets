#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> balances, vector<string> requests) {

    queue<pair<int, pair<int, int>>> q;
    // {cashbackTime, {accountIndex, cashback}}

    int n = requests.size();
    int m = balances.size();

    vector<int> result = balances;

    for (int i = 0; i < n; i++) {

        string st = requests[i];
        int len = st.size();

        int count = 0;
        int timestamp = 0;
        int holder = 0;
        int amount = 0;

        // Manual parsing
        for (int j = 0; j < len; j++) {

            if (st[j] == ' ') {
                count++;
                continue;
            }

            if (count == 1) {
                timestamp = timestamp * 10 + (st[j] - '0');
            }
            else if (count == 2) {
                holder = holder * 10 + (st[j] - '0');
            }
            else if (count == 3) {
                amount = amount * 10 + (st[j] - '0');
            }
        }

        // Process every cashback due before this request
        while (!q.empty() && q.front().first <= timestamp) {
            int idx = q.front().second.first;
            int cashback = q.front().second.second;

            result[idx] += cashback;
            q.pop();
        }

        int idx = holder - 1;

        // Invalid account
        if (idx < 0 || idx >= m) {
            return {-(i + 1)};
        }

        // Deposit
        if (st[0] == 'd') {

            result[idx] += amount;
        }

        // Withdraw
        else {

            // Insufficient funds
            if (result[idx] < amount) {
                return {-(i + 1)};
            }

            result[idx] -= amount;

            int cashback = amount / 50;
            int cashbackTime = timestamp + 86400;

            q.push({cashbackTime, {idx, cashback}});
        }
    }

    return result;
}