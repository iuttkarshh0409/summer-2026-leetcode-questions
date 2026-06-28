class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        radixSort(nums);

        int ans = 0;
        for (int i = 1; i < n; i++)
            ans = max(ans, nums[i] - nums[i - 1]);

        return ans;
    }

private:
    void radixSort(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        for (int exp = 1;; exp *= 10) {
            countingSort(nums, exp);

            if (exp > mx / 10)
                break;
        }
    }

    void countingSort(vector<int>& nums, int exp) {
        int n = nums.size();
        vector<int> output(n);
        int cnt[10] = {0};

        // Count occurrences of each digit
        for (int x : nums)
            cnt[(x / exp) % 10]++;

        // Prefix sums
        for (int i = 1; i < 10; i++)
            cnt[i] += cnt[i - 1];

        // Stable placement
        for (int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            output[--cnt[digit]] = nums[i];
        }

        nums = move(output);
    }
};