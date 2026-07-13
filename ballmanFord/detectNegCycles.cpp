#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class BellmanFord {
public:
    int n;
    vector<vector<int>> edges;
    vector<long long> dist;

    BellmanFord(int n, vector<vector<int>>& edges) {
        this->n = n;
        this->edges = edges;
        dist = vector<long long>(n, LLONG_MAX);
    }

    // Detects a negative cycle reachable from the given source
    bool detectNegativeCycle(int source) {

        dist[source] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i <= n - 1; i++) {

            bool updated = false;

            for (auto &edge : edges) {

                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] != LLONG_MAX &&
                    dist[u] + w < dist[v]) {

                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }

            // No updates means shortest paths are finalized
            if (!updated)
                break;
        }

        // One more pass to detect a negative cycle
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != LLONG_MAX &&
                dist[u] + w < dist[v]) {

                return true;
            }
        }

        return false;
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    BellmanFord bf(n, edges);

    if (bf.detectNegativeCycle(0))
        cout << "Negative cycle detected\n";
    else
        cout << "No negative cycle detected\n";

    return 0;
}