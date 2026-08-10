import java.util.*;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {

        // adjacency list
        List<int[]>[] graph = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] time : times) {
            int from = time[0];
            int to = time[1];
            int weight = time[2];

            graph[from].add(new int[]{to, weight});
        }

        // shortest[i] = shortest known time from k to i
        int[] shortest = new int[n + 1];
        Arrays.fill(shortest, Integer.MAX_VALUE);

        shortest[k] = 0;

        // {time, node}
        PriorityQueue<int[]> pq =
            new PriorityQueue<>((a, b) -> a[0] - b[0]);

        pq.offer(new int[]{0, k});

        while (!pq.isEmpty()) {
            int[] current = pq.poll();

            int time = current[0];
            int node = current[1];

            // Ignore outdated entry
            if (time > shortest[node]) {
                continue;
            }

            for (int[] edge : graph[node]) {
                int nextNode = edge[0];
                int weight = edge[1];

                int newTime = time + weight;

                if (newTime < shortest[nextNode]) {
                    shortest[nextNode] = newTime;
                    pq.offer(new int[]{newTime, nextNode});
                }
            }
        }

        // Find the time when the last node receives the signal
        int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (shortest[i] == Integer.MAX_VALUE) {
                return -1;
            }

            answer = Math.max(answer, shortest[i]);
        }

        return answer;
    }
}