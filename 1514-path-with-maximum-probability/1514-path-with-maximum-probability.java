import java.util.*;

class Solution {
    public double maxProbability(
        int n,
        int[][] edges,
        double[] succProb,
        int start_node,
        int end_node
    ) {

        // graph[node] = {neighbor, probability}
        List<double[]>[] graph = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        // Build undirected graph
        for (int i = 0; i < edges.length; i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            double probability = succProb[i];

            graph[u].add(new double[]{v, probability});
            graph[v].add(new double[]{u, probability});
        }

        // best[i] = maximum probability of reaching i
        double[] best = new double[n];
        best[start_node] = 1.0;

        // Max heap: highest probability first
        PriorityQueue<double[]> pq =
            new PriorityQueue<>((a, b) ->
                Double.compare(b[1], a[1])
            );

        // {node, probability}
        pq.offer(new double[]{start_node, 1.0});

        while (!pq.isEmpty()) {

            double[] current = pq.poll();

            int node = (int) current[0];
            double probability = current[1];

            // Ignore outdated entry
            if (probability < best[node]) {
                continue;
            }

            // We found the maximum-probability path
            if (node == end_node) {
                return probability;
            }

            for (double[] edge : graph[node]) {

                int next = (int) edge[0];
                double edgeProbability = edge[1];

                double newProbability =
                    probability * edgeProbability;

                if (newProbability > best[next]) {

                    best[next] = newProbability;

                    pq.offer(new double[]{
                        next,
                        newProbability
                    });
                }
            }
        }

        return 0.0;
    }
}