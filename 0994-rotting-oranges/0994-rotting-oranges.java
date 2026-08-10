import java.util.*;

class Solution {
    public int orangesRotting(int[][] grid) {

        int rows = grid.length;
        int cols = grid[0].length;

        Queue<int[]> queue = new LinkedList<>();

        int fresh = 0;

        // Add all initially rotten oranges
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == 2) {
                    queue.offer(new int[]{r, c});
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int[][] directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!queue.isEmpty() && fresh > 0) {

            int size = queue.size();

            // Process one minute
            for (int i = 0; i < size; i++) {

                int[] current = queue.poll();

                int r = current[0];
                int c = current[1];

                for (int[] direction : directions) {

                    int nr = r + direction[0];
                    int nc = c + direction[1];

                    // Valid cell + fresh orange
                    if (nr >= 0 && nr < rows &&
                        nc >= 0 && nc < cols &&
                        grid[nr][nc] == 1) {

                        // Make it rotten
                        grid[nr][nc] = 2;

                        fresh--;

                        queue.offer(new int[]{nr, nc});
                    }
                }
            }

            minutes++;
        }

        // Some fresh oranges could not be reached
        return fresh == 0 ? minutes : -1;
    }
}