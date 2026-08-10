#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        // {time, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<bool>> visited(
            n,
            vector<bool>(n, false)
        );

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!pq.empty()) {

            auto [time, r, c] = pq.top();
            pq.pop();

            // Reached destination
            if (r == n - 1 && c == n - 1) {
                return time;
            }

            for (auto& dir : directions) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                if (visited[nr][nc]) {
                    continue;
                }

                visited[nr][nc] = true;

                /*
                 * To enter this cell, water must be at least
                 * its elevation.
                 *
                 * The path has required:
                 *     `time`
                 *
                 * The new cell requires:
                 *     grid[nr][nc]
                 *
                 * Therefore:
                 *     newTime = max(time, grid[nr][nc])
                 */
                int newTime = max(
                    time,
                    grid[nr][nc]
                );

                pq.push({
                    newTime,
                    nr,
                    nc
                });
            }
        }

        return -1;
    }
};