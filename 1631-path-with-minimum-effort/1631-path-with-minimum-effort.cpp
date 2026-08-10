#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        // effort[r][c] = minimum effort needed
        // to reach (r, c)
        vector<vector<int>> effort(
            rows,
            vector<int>(cols, INT_MAX)
        );

        // {effort, row, col}
        //
        // Min heap: smallest effort first
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        effort[0][0] = 0;

        pq.push({0, 0, 0});

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!pq.empty()) {

            auto [currentEffort, r, c] = pq.top();
            pq.pop();

            // Ignore stale entry
            if (currentEffort > effort[r][c]) {
                continue;
            }

            // Reached destination
            if (r == rows - 1 && c == cols - 1) {
                return currentEffort;
            }

            for (auto& direction : directions) {

                int nr = r + direction[0];
                int nc = c + direction[1];

                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols) {
                    continue;
                }

                // Effort required for this individual move
                int edgeEffort = abs(
                    heights[nr][nc] - heights[r][c]
                );

                /*
                 * The path's effort is the maximum
                 * edge difference seen so far.
                 */
                int newEffort = max(
                    currentEffort,
                    edgeEffort
                );

                if (newEffort < effort[nr][nc]) {

                    effort[nr][nc] = newEffort;

                    pq.push({
                        newEffort,
                        nr,
                        nc
                    });
                }
            }
        }

        return 0;
    }
};