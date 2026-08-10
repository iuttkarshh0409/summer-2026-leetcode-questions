#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> graph;
    vector<int> disc;
    vector<int> low;
    vector<vector<int>> bridges;

    int timer = 0;

    void dfs(int node, int parent) {

        // Discovery time
        disc[node] = low[node] = timer++;

        for (int neighbor : graph[node]) {

            // Don't immediately go back through
            // the edge we came from.
            if (neighbor == parent) {
                continue;
            }

            // Already visited → back edge
            if (disc[neighbor] != -1) {

                low[node] = min(
                    low[node],
                    disc[neighbor]
                );

            }

            // Unvisited → DFS tree edge
            else {

                dfs(neighbor, node);

                // Neighbor may be able to reach
                // an earlier ancestor.
                low[node] = min(
                    low[node],
                    low[neighbor]
                );

                /*
                 * If neighbor cannot reach node
                 * or any ancestor of node, then
                 * removing node-neighbor disconnects
                 * the graph.
                 */
                if (low[neighbor] > disc[node]) {

                    bridges.push_back({
                        node,
                        neighbor
                    });
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {

        graph.assign(n, {});

        disc.assign(n, -1);
        low.assign(n, -1);

        bridges.clear();
        timer = 0;

        // Build undirected graph
        for (auto& edge : connections) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // The problem guarantees connectivity,
        // but looping makes the code robust.
        for (int i = 0; i < n; i++) {

            if (disc[i] == -1) {
                dfs(i, -1);
            }
        }

        return bridges;
    }
};