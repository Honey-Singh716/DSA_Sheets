#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<string> addends;
    string result;

    int mp[26];
    bool used[10];
    bool leading[26];

    int maxLen;
    int ans = 0;

    void dfs(int col, int row, int sum)
    {
        // Finished all columns
        if(col == maxLen)
        {
            if(sum == 0)
                ans++;
            return;
        }

        // Finished processing all addends for this column
        if(row == addends.size())
        {
            // No character in result at this column
            if(col >= result.size())
            {
                if(sum % 10 != 0)
                    return;

                dfs(col + 1, 0, sum / 10);
                return;
            }

            char ch = result[col];
            int idx = ch - 'A';

            int expected = sum % 10;
            int carry = sum / 10;

            // Already assigned
            if(mp[idx] != -1)
            {
                if(mp[idx] != expected)
                    return;

                dfs(col + 1, 0, carry);
            }
            else
            {
                if(used[expected])
                    return;

                if(expected == 0 && leading[idx])
                    return;

                used[expected] = true;
                mp[idx] = expected;

                dfs(col + 1, 0, carry);

                used[expected] = false;
                mp[idx] = -1;
            }

            return;
        }

        // Current addend has no character here
        if(col >= addends[row].size())
        {
            dfs(col, row + 1, sum);
            return;
        }

        char ch = addends[row][col];
        int idx = ch - 'A';

        // Already assigned
        if(mp[idx] != -1)
        {
            dfs(col,
                row + 1,
                sum + mp[idx]);
            return;
        }

        // Try every digit
        for(int d = 0; d <= 9; d++)
        {
            if(used[d])
                continue;

            if(d == 0 && leading[idx])
                continue;

            used[d] = true;
            mp[idx] = d;

            dfs(col,
                row + 1,
                sum + d);

            used[d] = false;
            mp[idx] = -1;
        }
    }

    int countSolutions(vector<string> words)
    {
        int n = words.size();

        result = words.back();
        words.pop_back();

        addends = words;

        memset(mp, -1, sizeof(mp));
        memset(used, false, sizeof(used));
        memset(leading, false, sizeof(leading));

        unordered_set<char> st;

        // Mark leading letters
        for(auto &w : addends)
        {
            reverse(w.begin(), w.end());

            if(w.size() > 1)
                leading[w.back() - 'A'] = true;

            maxLen = max(maxLen, (int)w.size());

            for(char c : w)
                st.insert(c);
        }

        reverse(result.begin(), result.end());

        if(result.size() > 1)
            leading[result.back() - 'A'] = true;

        maxLen = max(maxLen, (int)result.size());

        for(char c : result)
            st.insert(c);

        // Impossible
        if(st.size() > 10)
            return 0;

        dfs(0,0,0);

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<string> words =
    {
        "SEND",
        "MORE",
        "MONEY"
    };

    cout << obj.countSolutions(words);

    return 0;
}