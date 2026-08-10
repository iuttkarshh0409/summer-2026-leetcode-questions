#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    class DSU {
    private:
        vector<int> parent;

    public:
        DSU(int n) {
            parent.resize(n + 1);

            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }

            return parent[x];
        }

        bool unite(int a, int b) {

            int rootA = find(a);
            int rootB = find(b);

            // Already connected → cycle
            if (rootA == rootB) {
                return false;
            }

            parent[rootB] = rootA;

            return true;
        }
    };

    vector<int> findRedundantDirectedConnection(
        vector<vector<int>>& edges
    ) {

        int n = edges.size();

        // parent[v] = node that currently points to v
        vector<int> parent(n + 1, 0);

        // Candidates when a node has two parents
        vector<int> candidate1;
        vector<int> candidate2;

        // Find a node with two parents
        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (parent[v] == 0) {

                parent[v] = u;

            } else {

                // v already has a parent
                candidate1 = {parent[v], v};
                candidate2 = {u, v};

                // Ignore candidate2 for now
                edge[0] = -1;
                edge[1] = -1;
            }
        }

        // Check for cycle, ignoring candidate2
        DSU dsu(n);

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Skip candidate2
            if (u == -1) {
                continue;
            }

            if (!dsu.unite(u, v)) {

                // Cycle found
                if (candidate1.empty()) {
                    // No two-parent problem
                    return edge;
                }

                // Both two-parent + cycle
                return candidate1;
            }
        }

        // No cycle after removing candidate2
        // Therefore candidate2 is the redundant edge
        return candidate2;
    }
};