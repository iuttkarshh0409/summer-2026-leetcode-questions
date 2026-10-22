class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (auto& [num, count] : freq) {
            pq.push({count, num});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna