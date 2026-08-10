#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {

        int n = favorite.size();

        // indegree[i] = number of employees who favorite i
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }

        // depth[i] = longest chain ending at i
        //
        // Initially, each employee contributes itself.
        vector<int> depth(n, 1);

        queue<int> q;

        // Start with nodes that are NOT part of a cycle
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Remove all non-cycle nodes
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            int next = favorite[node];

            // Extend the longest chain into next
            depth[next] = max(
                depth[next],
                depth[node] + 1
            );

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }

        /*
         * After the topological pruning:
         *
         * indegree[i] > 0
         *
         * means i belongs to a cycle.
         */

        int largestCycle = 0;

        // Sum of all 2-cycles + their incoming chains
        int twoCycles = 0;

        for (int i = 0; i < n; i++) {

            if (indegree[i] == 0) {
                continue;
            }

            // Check for a mutual pair:
            //
            // i -> j
            // j -> i
            int j = favorite[i];

            if (favorite[j] == i) {

                // Longest chain ending at i
                // +
                // longest chain ending at j
                twoCycles += depth[i] + depth[j];
            }

            // Find cycle length
            int current = i;
            int cycleLength = 0;

            while (indegree[current] > 0) {

                indegree[current] = 0;

                cycleLength++;

                current = favorite[current];
            }

            largestCycle = max(
                largestCycle,
                cycleLength
            );
        }

        return max(largestCycle, twoCycles);
    }
};