class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> ans(n, 0);
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);
        order.push_back(0);

        for (int i = 0; i < (int)order.size(); ++i) {
            int u = order[i];

            for (auto [v, cost] : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                ans[0] += cost;
                order.push_back(v);
            }
        }

        for (int i = 1; i < n; ++i) {
            int v = order[i];
            int u = parent[v];

            for (auto [to, cost] : adj[v]) {
                if (to == u) {
                    ans[v] = ans[u] + (cost == 1 ? 1 : -1);
                    break;
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna