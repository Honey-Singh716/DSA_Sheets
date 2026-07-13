// #include<iostream>
// #include<queue>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int MaxCost(vector<vector<int>>& edges,int sr,int dst,int k){
    
//     queue<pair<pair<int,int>,int>> q;
    
//     q.push({{sr,0},0});
//     int distance = 0;

//     while(!q.empty()){
//         auto front = q.front();
//         q.pop();

//         int node = front.first.first;
//         int dist = front.first.second;
//         int n = front.second;

//         if(node == dst && n == k){
//             distance = max(distance, dist);
//         }

//         for(auto edge: edges){
//             int u = edge[0];
//             int v = edge[1];
//             int w = edge[2];

//             if(u == node){
//                 if(v == dst){
//                     q.push({{v, dist + w}, n});
//                 }
//                 else{
//                     q.push({{v, dist + w}, n + 1});
//                 }
//             }
//         }


//     }
//     return distance;
// }


// int main(){
//     int n = 5;
//     vector<vector<int>> edges = {{0,1,100},{1,2,100},{0,2,500}};
//     int sr = 0;
//     int dst = 2;
//     int k = 1;

//     int result = MaxCost(edges,sr,dst,k);

//     cout<<result<<" ";

//     return 0;
// }









#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int MaxCost(int n,
            vector<vector<int>>& edges,
            int src,
            int dst,
            int k)
{
    vector<vector<pair<int,int>>> adj(n);

    for(auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v,w});
    }

    queue<pair<pair<int,int>,int>> q;

    q.push({{src,0},0});

    int ans = -1;

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int node = curr.first.first;
        int cost = curr.first.second;
        int stops = curr.second;

        if(node == dst && stops == k)
        {
            ans = max(ans,cost);
            continue;
        }

        if(stops > k)
        {
            continue;
        }

        for(auto &nbr : adj[node])
        {
            int nextNode = nbr.first;
            int weight = nbr.second;

            if(nextNode == dst)
            {
                q.push({{nextNode,cost + weight},stops});
            }
            else
            {
                q.push({{nextNode,cost + weight},stops + 1});
            }
        }
    }

    return ans;
}

int main()
{
    int n = 3;

    vector<vector<int>> edges =
    {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };

    int src = 0;
    int dst = 2;
    int k = 1;

    cout << MaxCost(n,edges,src,dst,k);

    return 0;
}