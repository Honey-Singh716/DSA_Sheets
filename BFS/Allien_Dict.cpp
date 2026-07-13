#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

string alienOrder(vector<string>& words)
{
    vector<unordered_set<int>> adj(26);
    vector<int> indegree(26, 0);
    vector<bool> exists(26, false);

    // Mark existing characters
    for(auto &word : words)
    {
        for(char ch : word)
        {
            exists[ch - 'a'] = true;
        }
    }

    // Build graph
    for(int i = 1; i < words.size(); i++)
    {
        string prev = words[i - 1];
        string curr = words[i];

        int len = min(prev.size(), curr.size());

        bool found = false;

        for(int j = 0; j < len; j++)
        {
            if(prev[j] != curr[j])
            {
                int u = prev[j] - 'a';
                int v = curr[j] - 'a';

                // Avoid duplicate edges
                if(adj[u].find(v) == adj[u].end())
                {
                    adj[u].insert(v);
                    indegree[v]++;
                }

                found = true;
                break;
            }
        }

        // Invalid prefix case
        if(!found && prev.size() > curr.size())
        {
            return "";
        }
    }

    queue<int> q;

    int totalChars = 0;

    for(int i = 0; i < 26; i++)
    {
        if(exists[i])
        {
            totalChars++;

            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    string order;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        order.push_back(node + 'a');

        for(auto neigh : adj[node])
        {
            indegree[neigh]--;

            if(indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }

    // Cycle detection
    if(order.size() != totalChars)
    {
        return "";
    }

    return order;
}

int main()
{
    vector<string> words =
    {
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"
    };

    string ans = alienOrder(words);

    if(ans.empty())
    {
        cout << "Invalid Dictionary";
    }
    else
    {
        cout << ans;
    }

    return 0;
}