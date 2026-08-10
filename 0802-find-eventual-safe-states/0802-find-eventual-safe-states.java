import java.util.*;

class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {

        int n = graph.length;

        // 0 = unvisited
        // 1 = currently visiting
        // 2 = safe
        // 3 = unsafe
        int[] state = new int[n];

        List<Integer> result = new ArrayList<>();

        for (int node = 0; node < n; node++) {
            if (dfs(node, graph, state)) {
                result.add(node);
            }
        }

        return result;
    }

    private boolean dfs(
        int node,
        int[][] graph,
        int[] state
    ) {

        // Currently in this DFS path → cycle
        if (state[node] == 1) {
            return false;
        }

        // Already determined to be unsafe
        if (state[node] == 3) {
            return false;
        }

        // Already determined to be safe
        if (state[node] == 2) {
            return true;
        }

        // Mark as currently visiting
        state[node] = 1;

        for (int next : graph[node]) {

            if (!dfs(next, graph, state)) {
                state[node] = 3;
                return false;
            }
        }

        // Every path from node eventually reaches a safe node
        state[node] = 2;

        return true;
    }
}