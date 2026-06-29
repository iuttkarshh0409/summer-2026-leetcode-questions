class Solution {
public:
    int n;
    vector<vector<int>> cost;
    vector<vector<int>> memo;

    int solve(int i, int k) {
        if (i == n) return 0;
        if (k == 0) return 1e9;

        if (memo[i][k] != -1)
            return memo[i][k];

        int ans = 1e9;

        for (int j = i; j < n; j++) {
            ans = min(ans, cost[i][j] + solve(j + 1, k - 1));
        }

        return memo[i][k] = ans;
    }

    int minDistance(vector<int>& houses, int K) {
        sort(houses.begin(), houses.end());
        n = houses.size();

        cost.assign(n, vector<int>(n, 0));

        // Precompute cost[i][j]
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int mid = (i + j) / 2;
                for (int t = i; t <= j; t++) {
                    cost[i][j] += abs(houses[t] - houses[mid]);
                }
            }
        }

        memo.assign(n, vector<int>(K + 1, -1));

        return solve(0, K);
    }
};