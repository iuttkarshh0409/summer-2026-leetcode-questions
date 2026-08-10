import java.util.*;

class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> result = new ArrayList<>();

        List<Integer> path = new ArrayList<>();
        path.add(0);

        dfs(0, graph, path, result);

        return result;
    }

    private void dfs(
        int node,
        int[][] graph,
        List<Integer> path,
        List<List<Integer>> result
    ) {
        // Reached target
        if (node == graph.length - 1) {
            result.add(new ArrayList<>(path));
            return;
        }

        // Explore every neighbor
        for (int next : graph[node]) {

            // Choose
            path.add(next);

            // Explore
            dfs(next, graph, path, result);

            // Undo choice
            path.remove(path.size() - 1);
        }
    }
}