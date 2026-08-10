import java.util.*;

class Solution {
    public int[] shortestAlternatingPaths(
        int n,
        int[][] redEdges,
        int[][] blueEdges
    ) {

        // graph[node][color]
        // color 0 = red
        // color 1 = blue
        List<Integer>[][] graph = new ArrayList[2][n];

        for (int color = 0; color < 2; color++) {
            for (int node = 0; node < n; node++) {
                graph[color][node] = new ArrayList<>();
            }
        }

        // Red edges
        for (int[] edge : redEdges) {
            graph[0][edge[0]].add(edge[1]);
        }

        // Blue edges
        for (int[] edge : blueEdges) {
            graph[1][edge[0]].add(edge[1]);
        }

        int[] answer = new int[n];
        Arrays.fill(answer, -1);

        // visited[node][color]
        // Have we reached node using an edge of this color?
        boolean[][] visited = new boolean[n][2];

        Queue<int[]> queue = new LinkedList<>();

        /*
         * We can start with either color because
         * there is no previous edge.
         */
        queue.offer(new int[]{0, 0, 0});
        queue.offer(new int[]{0, 1, 0});

        visited[0][0] = true;
        visited[0][1] = true;

        while (!queue.isEmpty()) {

            int[] current = queue.poll();

            int node = current[0];
            int lastColor = current[1];
            int distance = current[2];

            // First time reaching this node is shortest
            if (answer[node] == -1) {
                answer[node] = distance;
            }

            // We need the opposite color next
            int nextColor = 1 - lastColor;

            for (int next : graph[nextColor][node]) {

                if (visited[next][nextColor]) {
                    continue;
                }

                visited[next][nextColor] = true;

                queue.offer(new int[]{
                    next,
                    nextColor,
                    distance + 1
                });
            }
        }

        return answer;
    }
}