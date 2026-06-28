class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> neg, pos;

        for (int x : nums) {
            if (x < 0)
                neg.push_back(-x);
            else
                pos.push_back(x);
        }

        radixSort(pos);
        radixSort(neg);

        nums.clear();

        // Restore negatives in reverse order
        for (int i = neg.size() - 1; i >= 0; i--)
            nums.push_back(-neg[i]);

        // Append positives
        for (int x : pos)
            nums.push_back(x);

        return nums;
    }

private:
    void radixSort(vector<int>& arr) {
        if (arr.empty()) return;

        int mx = *max_element(arr.begin(), arr.end());

        for (int exp = 1; mx / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }

    void countingSort(vector<int>& arr, int exp) {
        int n = arr.size();
        vector<int> output(n);
        int count[10] = {0};

        // Count digit frequencies
        for (int x : arr)
            count[(x / exp) % 10]++;

        // Prefix sums
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Stable placement
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
        }

        arr = move(output);
    }
};