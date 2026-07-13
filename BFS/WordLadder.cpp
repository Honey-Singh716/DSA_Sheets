#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool freq(string &a, string &b)
{
    if (a.size() != b.size())
        return false;

    int diff = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            diff++;
    }

    return diff == 1;
}

int LadderLength(string beginWord,
                 string endWord,
                 vector<string> &wordList)
{
    bool found = false;

    for (auto &w : wordList)
    {
        if (w == endWord)
        {
            found = true;
            break;
        }
    }

    if (!found)
        return 0;

    wordList.insert(wordList.begin(), beginWord);

    int n = wordList.size();

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (freq(wordList[i], wordList[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> visited(n, 0);

    queue<pair<int, int>> q;

    q.push({0, 1});

    visited[0] = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int node = cur.first;
        int level = cur.second;

        if (wordList[node] == endWord)
            return level;

        for (int next : adj[node])
        {
            if (!visited[next])
            {
                visited[next] = 1;
                q.push({next, level + 1});
            }
        }
    }

    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList =
    {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    cout << LadderLength(beginWord,
                         endWord,
                         wordList);
}