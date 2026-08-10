import java.util.*;

class Solution {
    public int openLock(String[] deadends, String target) {

        Set<String> dead = new HashSet<>(Arrays.asList(deadends));

        // Starting position is blocked
        if (dead.contains("0000")) {
            return -1;
        }

        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.offer("0000");
        visited.add("0000");

        int moves = 0;

        while (!queue.isEmpty()) {

            int size = queue.size();

            for (int i = 0; i < size; i++) {

                String current = queue.poll();

                // Reached target
                if (current.equals(target)) {
                    return moves;
                }

                // Generate all possible next states
                for (String next : getNeighbors(current)) {

                    if (dead.contains(next) || visited.contains(next)) {
                        continue;
                    }

                    visited.add(next);
                    queue.offer(next);
                }
            }

            moves++;
        }

        return -1;
    }

    private List<String> getNeighbors(String state) {

        List<String> neighbors = new ArrayList<>();

        char[] chars = state.toCharArray();

        for (int i = 0; i < 4; i++) {

            char original = chars[i];

            // Rotate upward: 0 -> 1, 9 -> 0
            chars[i] = original == '9'
                    ? '0'
                    : (char) (original + 1);

            neighbors.add(new String(chars));

            // Rotate downward: 0 -> 9, 1 -> 0
            chars[i] = original == '0'
                    ? '9'
                    : (char) (original - 1);

            neighbors.add(new String(chars));

            // Restore original digit
            chars[i] = original;
        }

        return neighbors;
    }
}