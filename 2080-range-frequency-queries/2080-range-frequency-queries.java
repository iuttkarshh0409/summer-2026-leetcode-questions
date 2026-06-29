class RangeFreqQuery {

    private Map<Integer, List<Integer>> map;

    public RangeFreqQuery(int[] arr) {

        map = new HashMap<>();

        for (int i = 0; i < arr.length; i++) {
            map.putIfAbsent(arr[i], new ArrayList<>());
            map.get(arr[i]).add(i);
        }
    }

    public int query(int left, int right, int value) {

        if (!map.containsKey(value))
            return 0;

        List<Integer> list = map.get(value);

        int l = lowerBound(list, left);
        int r = upperBound(list, right);

        return r - l;
    }

    private int lowerBound(List<Integer> list, int target) {

        int lo = 0, hi = list.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (list.get(mid) >= target)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }

    private int upperBound(List<Integer> list, int target) {

        int lo = 0, hi = list.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (list.get(mid) > target)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
}