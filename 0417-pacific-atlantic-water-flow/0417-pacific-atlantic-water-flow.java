import java.util.*;

class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {

        int rows = heights.length;
        int cols = heights[0].length;

        boolean[][] pacific = new boolean[rows][cols];
        boolean[][] atlantic = new boolean[rows][cols];

        Queue<int[]> pacificQueue = new LinkedList<>();
        Queue<int[]> atlanticQueue = new LinkedList<>();

        // Pacific: top row + left column
        for (int r = 0; r < rows; r++) {
            pacific[r][0] = true;
            pacificQueue.offer(new int[]{r, 0});
        }

        for (int c = 0; c < cols; c++) {
            if (!pacific[0][c]) {
                pacific[0][c] = true;
                pacificQueue.offer(new int[]{0, c});
            }
        }

        // Atlantic: bottom row + right column
        for (int r = 0; r < rows; r++) {
            atlantic[r][cols - 1] = true;
            atlanticQueue.offer(new int[]{r, cols - 1});
        }

        for (int c = 0; c < cols; c++) {
            if (!atlantic[rows - 1][c]) {
                atlantic[rows - 1][c] = true;
                atlanticQueue.offer(new int[]{rows - 1, c});
            }
        }

        int[][] directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        bfs(
            heights,
            pacificQueue,
            pacific,
            directions
        );

        bfs(
            heights,
            atlanticQueue,
            atlantic,
            directions
        );

        List<List<Integer>> result = new ArrayList<>();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // Can reach BOTH oceans
                if (pacific[r][c] && atlantic[r][c]) {
                    result.add(
                        Arrays.asList(r, c)
                    );
                }
            }
        }

        return result;
    }

    private void bfs(
        int[][] heights,
        Queue<int[]> queue,
        boolean[][] visited,
        int[][] directions
    ) {

        int rows = heights.length;
        int cols = heights[0].length;

        while (!queue.isEmpty()) {

            int[] current = queue.poll();

            int r = current[0];
            int c = current[1];

            for (int[] direction : directions) {

                int nr = r + direction[0];
                int nc = c + direction[1];

                // Outside grid
                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols) {
                    continue;
                }

                // Already visited
                if (visited[nr][nc]) {
                    continue;
                }

                /*
                 * Reverse flow:
                 *
                 * We can move from current to neighbor
                 * if neighbor is at least as high as current.
                 */
                if (heights[nr][nc] < heights[r][c]) {
                    continue;
                }

                visited[nr][nc] = true;
                queue.offer(new int[]{nr, nc});
            }
        }
    }
}