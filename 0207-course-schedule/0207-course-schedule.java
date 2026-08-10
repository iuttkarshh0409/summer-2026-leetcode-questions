import java.util.*;

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {

        // Build adjacency list
        List<Integer>[] graph = new ArrayList[numCourses];

        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prereq = prerequisite[1];

            graph[prereq].add(course);
        }

        // 0 = unvisited
        // 1 = currently visiting
        // 2 = completely processed
        int[] state = new int[numCourses];

        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, graph, state)) {
                return false;
            }
        }

        return true;
    }

    private boolean dfs(
        int course,
        List<Integer>[] graph,
        int[] state
    ) {
        // Found a node currently in our DFS path
        if (state[course] == 1) {
            return false;
        }

        // Already completely processed
        if (state[course] == 2) {
            return true;
        }

        // Mark as currently visiting
        state[course] = 1;

        for (int next : graph[course]) {
            if (!dfs(next, graph, state)) {
                return false;
            }
        }

        // Finished processing this course
        state[course] = 2;

        return true;
    }
}