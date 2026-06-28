class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].size();

        // order[t] = indices sorted by last t digits
        vector<vector<int>> order(m + 1);
        vector<int> idx(n);

        iota(idx.begin(), idx.end(), 0);

        // Initially (trim = 0), order is by original index
        order[0] = idx;

        // Build sorted order for every trim length
        for (int t = 1; t <= m; t++) {
            vector<vector<int>> bucket(10);

            int pos = m - t;

            for (int id : order[t - 1]) {
                bucket[nums[id][pos] - '0'].push_back(id);
            }

            order[t].clear();

            for (int d = 0; d < 10; d++) {
                for (int id : bucket[d]) {
                    order[t].push_back(id);
                }
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int k = q[0];
            int trim = q[1];
            ans.push_back(order[trim][k - 1]);
        }

        return ans;
    }
};