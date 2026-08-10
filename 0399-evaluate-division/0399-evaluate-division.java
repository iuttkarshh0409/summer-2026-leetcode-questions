import java.util.*;

class Solution {

    public double[] calcEquation(
        List<List<String>> equations,
        double[] values,
        List<List<String>> queries
    ) {

        // variable -> (neighbor -> ratio)
        Map<String, Map<String, Double>> graph = new HashMap<>();

        // Build graph
        for (int i = 0; i < equations.size(); i++) {

            String a = equations.get(i).get(0);
            String b = equations.get(i).get(1);

            double value = values[i];

            // a / b = value
            graph.putIfAbsent(a, new HashMap<>());
            graph.putIfAbsent(b, new HashMap<>());

            graph.get(a).put(b, value);

            // b / a = 1 / value
            graph.get(b).put(a, 1.0 / value);
        }

        double[] result = new double[queries.size()];

        for (int i = 0; i < queries.size(); i++) {

            String start = queries.get(i).get(0);
            String target = queries.get(i).get(1);

            // Variable doesn't exist
            if (!graph.containsKey(start) ||
                !graph.containsKey(target)) {

                result[i] = -1.0;
                continue;
            }

            if (start.equals(target)) {
                result[i] = 1.0;
                continue;
            }

            Set<String> visited = new HashSet<>();

            result[i] = dfs(
                start,
                target,
                1.0,
                graph,
                visited
            );
        }

        return result;
    }

    private double dfs(
        String current,
        String target,
        double product,
        Map<String, Map<String, Double>> graph,
        Set<String> visited
    ) {

        if (current.equals(target)) {
            return product;
        }

        visited.add(current);

        for (Map.Entry<String, Double> entry :
             graph.get(current).entrySet()) {

            String next = entry.getKey();
            double weight = entry.getValue();

            if (visited.contains(next)) {
                continue;
            }

            double result = dfs(
                next,
                target,
                product * weight,
                graph,
                visited
            );

            if (result != -1.0) {
                return result;
            }
        }

        return -1.0;
    }
}