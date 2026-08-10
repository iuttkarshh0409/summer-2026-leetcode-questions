import java.util.*;

class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {

        // Special case
        if (n == 1) {
            return List.of(0);
        }

        // Build adjacency list
        List<Integer>[] graph = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        // Degree = number of neighbors
        int[] degree = new int[n];

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].add(v);
            graph[v].add(u);

            degree[u]++;
            degree[v]++;
        }

        // Start with all leaves
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                queue.offer(i);
            }
        }

        int remainingNodes = n;

        while (remainingNodes > 2) {

            int leaves = queue.size();

            remainingNodes -= leaves;

            for (int i = 0; i < leaves; i++) {

                int leaf = queue.poll();

                for (int neighbor : graph[leaf]) {

                    degree[neighbor]--;

                    // Neighbor became a leaf
                    if (degree[neighbor] == 1) {
                        queue.offer(neighbor);
                    }
                }
            }
        }

        return new ArrayList<>(queue);
    }
}