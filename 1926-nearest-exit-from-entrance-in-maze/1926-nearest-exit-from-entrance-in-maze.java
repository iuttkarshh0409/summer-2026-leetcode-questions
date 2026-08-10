import java.util.*;

class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {

        int rows = maze.length;
        int cols = maze[0].length;

        Queue<int[]> queue = new LinkedList<>();

        // {row, col, distance}
        queue.offer(new int[]{
            entrance[0],
            entrance[1],
            0
        });

        // Mark entrance as visited
        maze[entrance[0]][entrance[1]] = '+';

        int[][] directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!queue.isEmpty()) {

            int[] current = queue.poll();

            int r = current[0];
            int c = current[1];
            int distance = current[2];

            for (int[] direction : directions) {

                int nr = r + direction[0];
                int nc = c + direction[1];

                // Outside the maze
                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols) {
                    continue;
                }

                // Wall or already visited
                if (maze[nr][nc] != '.') {
                    continue;
                }

                // We found an exit
                if (nr == 0 || nr == rows - 1 ||
                    nc == 0 || nc == cols - 1) {
                    return distance + 1;
                }

                // Mark visited
                maze[nr][nc] = '+';

                queue.offer(new int[]{
                    nr,
                    nc,
                    distance + 1
                });
            }
        }

        return -1;
    }
}