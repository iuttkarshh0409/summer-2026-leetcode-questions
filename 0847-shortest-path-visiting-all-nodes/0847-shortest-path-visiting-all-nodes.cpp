#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();

        // All nodes visited:
        // 111...111
        int allVisited = (1 << n) - 1;

        /*
         * visited[node][mask]
         *
         * Have we already reached `node`
         * having visited exactly the nodes in `mask`?
         */
        vector<vector<bool>> visited(
            n,
            vector<bool>(1 << n, false)
        );

        // {currentNode, visitedMask}
        queue<pair<int, int>> q;

        /*
         * We can start from ANY node.
         *
         * So put every node into the initial BFS layer.
         */
        for (int node = 0; node < n; node++) {

            int mask = 1 << node;

            q.push({node, mask});

            visited[node][mask] = true;
        }

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto [node, mask] = q.front();
                q.pop();

                // Have we visited every node?
                if (mask == allVisited) {
                    return steps;
                }

                for (int neighbor : graph[node]) {

                    /*
                     * Mark neighbor as visited.
                     *
                     * OR sets that bit to 1.
                     */
                    int newMask =
                        mask | (1 << neighbor);

                    if (visited[neighbor][newMask]) {
                        continue;
                    }

                    visited[neighbor][newMask] = true;

                    q.push({
                        neighbor,
                        newMask
                    });
                }
            }

            steps++;
        }

        return -1;
    }
};