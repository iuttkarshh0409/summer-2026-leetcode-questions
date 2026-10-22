class SnapshotArray {
    private List<int[]>[] history;
    private int snapId;

    public SnapshotArray(int length) {
        history = new ArrayList[length];
        snapId = 0;

        for (int i = 0; i < length; i++) {
            history[i] = new ArrayList<>();
            history[i].add(new int[]{0, 0});
        }
    }

    public void set(int index, int val) {
        List<int[]> list = history[index];

        if (list.get(list.size() - 1)[0] == snapId) {
            list.get(list.size() - 1)[1] = val;
        } else {
            list.add(new int[]{snapId, val});
        }
    }

    public int snap() {
        return snapId++;
    }

    public int get(int index, int snap_id) {
        List<int[]> list = history[index];
        int left = 0, right = list.size() - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (list.get(mid)[0] <= snap_id) {
                result = list.get(mid)[1];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna