import java.util.*;

class Solution {
    public int minReorder(int n, int[][] connections) {

        List<int[]>[] graph = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] connection : connections) {
            int from = connection[0];
            int to = connection[1];

            // Original direction: from -> to
            graph[from].add(new int[]{to, 1});

            // Reverse direction for traversal
            graph[to].add(new int[]{from, 0});
        }

        return dfs(0, -1, graph);
    }

    private int dfs(int city, int parent, List<int[]>[] graph) {

        int changes = 0;

        for (int[] edge : graph[city]) {
            int next = edge[0];
            int needsReorder = edge[1];

            // Don't go back to parent
            if (next == parent) {
                continue;
            }

            // This road points away from city 0
            changes += needsReorder;

            changes += dfs(next, city, graph);
        }

        return changes;
    }
}