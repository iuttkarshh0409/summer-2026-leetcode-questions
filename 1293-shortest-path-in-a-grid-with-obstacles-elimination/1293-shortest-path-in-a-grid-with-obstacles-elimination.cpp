#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();

        // State: {row, col, remaining eliminations}
        queue<array<int, 3>> q;

        // visited[r][c] = maximum number of eliminations
        // remaining that we have had when reaching this cell
        vector<vector<int>> visited(
            rows,
            vector<int>(cols, -1)
        );

        q.push({0, 0, k});
        visited[0][0] = k;

        int steps = 0;

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto [r, c, remaining] = q.front();
                q.pop();

                // Reached destination
                if (r == rows - 1 && c == cols - 1) {
                    return steps;
                }

                for (auto& direction : directions) {

                    int nr = r + direction[0];
                    int nc = c + direction[1];

                    // Outside grid
                    if (nr < 0 || nr >= rows ||
                        nc < 0 || nc >= cols) {
                        continue;
                    }

                    int newRemaining = remaining - grid[nr][nc];

                    // Can't eliminate this obstacle
                    if (newRemaining < 0) {
                        continue;
                    }

                    /*
                     * Only visit if we arrive with MORE
                     * elimination power than before.
                     */
                    if (newRemaining <= visited[nr][nc]) {
                        continue;
                    }

                    visited[nr][nc] = newRemaining;

                    q.push({
                        nr,
                        nc,
                        newRemaining
                    });
                }
            }

            steps++;
        }

        return -1;
    }
};