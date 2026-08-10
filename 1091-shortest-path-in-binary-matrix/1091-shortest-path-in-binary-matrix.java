import java.util.*;

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {

        int n = grid.length;

        // Start or end is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        Queue<int[]> queue = new LinkedList<>();

        // {row, col, distance}
        queue.offer(new int[]{0, 0, 1});

        // Mark as visited
        grid[0][0] = 1;

        int[][] directions = {
            {-1, -1},
            {-1,  0},
            {-1,  1},
            { 0, -1},
            { 0,  1},
            { 1, -1},
            { 1,  0},
            { 1,  1}
        };

        while (!queue.isEmpty()) {

            int[] current = queue.poll();

            int r = current[0];
            int c = current[1];
            int distance = current[2];

            // Reached target
            if (r == n - 1 && c == n - 1) {
                return distance;
            }

            for (int[] direction : directions) {

                int nr = r + direction[0];
                int nc = c + direction[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    // Mark visited
                    grid[nr][nc] = 1;

                    queue.offer(new int[]{
                        nr,
                        nc,
                        distance + 1
                    });
                }
            }
        }

        return -1;
    }
}