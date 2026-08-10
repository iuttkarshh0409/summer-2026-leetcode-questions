import java.util.*;

class Solution {
    public boolean isBipartite(int[][] graph) {

        int n = graph.length;

        // -1 = uncolored
        //  0 = color 0
        //  1 = color 1
        int[] color = new int[n];

        Arrays.fill(color, -1);

        for (int start = 0; start < n; start++) {

            // Graph may be disconnected
            if (color[start] != -1) {
                continue;
            }

            Queue<Integer> queue = new LinkedList<>();

            queue.offer(start);
            color[start] = 0;

            while (!queue.isEmpty()) {

                int node = queue.poll();

                for (int neighbor : graph[node]) {

                    // Not colored yet
                    if (color[neighbor] == -1) {

                        // Must have opposite color
                        color[neighbor] = 1 - color[node];

                        queue.offer(neighbor);
                    }

                    // Same color on both ends → not bipartite
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
}